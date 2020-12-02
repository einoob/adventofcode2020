/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:15:03 by elindber          #+#    #+#             */
/*   Updated: 2020/12/02 11:15:03 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"

void	free_2d_array(char **array)
{
	int		y;

	y = -1;
	while (array[++y] != NULL)
	{
		free(array[y]);
	}
}

int		main(int ac, char **av)
{
	char	*line;
	char	**elements;
	char	to_find;
	int		count;
	int		result;
	int		fd;
	int		min;
	int		max;
	int		i;

	fd = open(av[1], O_RDONLY);
	i = 0;
	count = 0;
	result = 0;
	if (ac != 2)
		return (-1);
	while (get_next_line(fd, &line))
	{
		min = ft_atoi(line);
		while (line[i] != '-')
			i++;
		max = -1 * ft_atoi(&line[i]);
		while (line[i] != ':')
			i++;
		to_find = line[i - 1];
		elements = ft_strsplit(line, ' ');
		i = -1;
		while (elements[2][++i] != '\0')
		{
			if (elements[2][i] == to_find && (i + 1 == min || i + 1 == max))
			{
				count++;
			}
		}
		if (count == 1)
		{
			ft_printf("Valid: %d %d %d\n%s\n%s\n", min, max, i - 1, line, elements[2]);
			result++;
		}
		else
		{
			ft_printf("INVALID: %d %d %d\n%s\n%s\n", min, max, i -1, line, elements[2]);
		}
		i = 0;
		count = 0;
		free_2d_array(elements);
		free(line);
	}
	close(fd);
	ft_printf("Amount of valid passwordsz: %d\n", result);
	system("leaks a.out");
	return (0);
}