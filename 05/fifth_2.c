/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifth_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 09:43:06 by elindber          #+#    #+#             */
/*   Updated: 2020/12/05 09:43:06 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"
#include <stdio.h>

int		find_missing(int *ids)
{
	int		i;

	i = 0;
	while (++i < 850)
	{
		if (ids[i - 1] != (ids[i] - 1))
			return (ids[i - 1] + 1);
	}
	return (-1);
}

int		main(int ac, char **av)
{
	int 	fd;
	int		pass_id;
	int		ids[850];
	int		tab;
	int		i;
	int		max;
	int		min;
	int		seat;
	int		result;
	char	*line;

	if (ac != 2)
		return (-1);
	i = 0;
	tab = 0;
	pass_id = 0;
	result = 0;
	min = 0;
	max = 127;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		while (i < 6)
		{
			if (line[i] == 'F')
				max -= ((max - min) / 2) + 1;
			if (line[i] == 'B')
				min += ((max - min) / 2) + 1;
			i++;
		}
		pass_id = line[i] == 'F' ? min : max;
		min = 0;
		max = 7;
		while (i < 9)
		{
			if (line[i] == 'L')
				max -= ((max - min) / 2) + 1;
			if (line[i] == 'R')
				min += ((max - min) / 2) + 1;
			i++;
		}
		seat = line[i] == 'L' ? min : max;
		pass_id = pass_id * 8 + seat;
		ids[tab] = pass_id;
		i = 0;
		tab++;
		min = 0;
		max = 127;
		free(line);
	}
	i = -1;
	while (++i < 849)
	{
		if (ids[i] > ids[i + 1])
		{
			tab = ids[i];
			ids[i] = ids[i + 1];
			ids[i + 1] = tab;
			i = -1;
		}
	}
	result = find_missing(ids);
	ft_printf("missing pass id: %d\n", result);
	return (0);
}