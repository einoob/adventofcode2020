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

int		check_upleft(char **map, int y, int x)
{
	y--;
	x--;
	while (y >= 0)
	{
		if (map[y][x] != '.')
			return (map[y][x] == '#');
		y--;
		x--;
	}
	return (0);
}

int		check_upright(char **map, int y, int x)
{
	y--;
	x++;
	while (y >= 0)
	{
		if (map[y][x] != '.')
			return (map[y][x] == '#');
		y--;
		x++;
	}
	return (0);
}

int		check_downleft(char **map, int y, int x)
{
	y++;
	x--;
	while (map[y] != NULL)
	{
		if (map[y][x] != '.')
			return (map[y][x] == '#');
		y++;
		x--;
	}
	return (0);
}

int		check_downright(char **map, int y, int x)
{
	y++;
	x++;
	while (map[y] != NULL)
	{
		if (map[y][x] != '.')
			return (map[y][x] == '#');
		y++;
		x++;
	}
	return (0);
}

int		check_up(char **map, int y, int x)
{
	y--;
	while (y >= 0)
	{
		if (map[y][x] != '.')
			return (map[y][x] == '#');
		y--;
	}
	return (0);
}

int		check_down(char **map, int y, int x)
{
	y++;
	while (map[y] != NULL)
	{
		if (map[y][x] != '.')
			return (map[y][x] == '#');
		y++;
	}
	return (0);
}

int		check_right(char **map, int y, int x)
{
	x++;
	while (map[y][x] != '\r')
	{
		if (map[y][x] != '.')
			return (map[y][x] == '#');
		x++;
	}
	return (0);
}

int		check_left(char **map, int y, int x)
{
	x--;
	while (x >= 0)
	{
		if (map[y][x] != '.')
			return (map[y][x] == '#');
		x--;
	}
	return (0);
}

int		check_seats(char **map, char **copy, int y, int x)
{
	int		reserved;

	reserved = 0;
	if (x > 0)
		reserved += check_left(map, y, x);
	if (y > 0)
		reserved += check_up(map, y, x);
	if (map[y + 1] != NULL)
		reserved += check_down(map, y, x);
	if (map[y][x + 1] != '\r')
		reserved += check_right(map, y, x);
	if (x > 0 && y > 0)
		reserved += check_upleft(map, y, x);
	if (x > 0 && map[y + 1] != NULL)
		reserved += check_downleft(map, y, x);
	if (map[y][x + 1] != '\r' && y > 0)
		reserved += check_upright(map, y, x);
	if (map[y][x + 1] != '\r' && map[y + 1] != NULL)
		reserved += check_downright(map, y, x);
	if (reserved > 4 && map[y][x] == '#')
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
