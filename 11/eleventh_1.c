/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eleventh_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:56:09 by elindber          #+#    #+#             */
/*   Updated: 2020/12/11 10:56:09 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"

int		check_seats(char **map, char **copy, int y, int x)
{
	int a;
	int b;
	int	reserved;

	a = y == 0 ? y : y - 1;
	b = x == 0 ? x : x - 1;
	reserved = 0;
	while (map[a] != NULL && a <= y + 1)
	{
		while (map[a][b] != '\0' && b <= x + 1)
		{
			if (a == y && b == x)
				b++;
			else
			{
				if (map[a][b] == '#')
					reserved++;
				b++;
			}
		}
		b = x == 0 ? x : x - 1;
		a++;
	}
	if (reserved > 3 && map[y][x] == '#')
	{
		copy[y][x] = 'L';
		return (1);
	}
	else if (reserved == 0 && map[y][x] == 'L')
	{
		copy[y][x] = '#';
		return (1);
	}
	return (0);
}

int		iterate_map(char **map, char **copy)
{
	int		i;
	int		y;
	int		change;

	i = -1;
	y = -1;
	change = 0;
	while (map[++y] != NULL)
	{
		while (map[y][++i] != '\0')
		{
			if (check_seats(map, copy, y, i))
				change = 1;
		}
		i = -1;
	}
	y = -1;
	while (copy[++y] != NULL)
	{
		while (copy[y][++i] != '\0')
			map[y][i] = copy[y][i];
		i = -1;
	}
	return (change);
}

long	count_occupied(char **map)
{
	int		y;
	int		x;
	long	count;

	y = -1;
	x = -1;
	count = 0;
	while (map[++y] != NULL)
	{
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == '#')
				count++;
		}
		x = -1;
	}
	return (count);
}

long	resolve_seating(char **map, char **copy)
{
	long	round;

	round = 0;
	while (iterate_map(map, copy))
		round++;
	round = count_occupied(map);
	return (round);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;
	char	*map[99];
	char	*copy[99];

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (-1);
	i = -1;
	while (get_next_line(fd, &line))
	{
		map[++i] = ft_strdup(line);
		copy[i] = ft_strdup(line);
		free(line);
	}
	map[i + 1] = NULL;
	copy[i + 1] = NULL;
	ft_printf("occupied seats %ld\n", resolve_seating(map, copy));
}