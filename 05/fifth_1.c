/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifth_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 09:09:23 by elindber          #+#    #+#             */
/*   Updated: 2020/12/05 09:09:23 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int 	fd;
	int		pass_id;
	int		i;
	int		max;
	int		min;
	int		seat;
	int		result;
	char	*line;

	if (ac != 2)
		return (-1);
	i = 0;
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
		result = pass_id > result ? pass_id : result;
		i = 0;
		min = 0;
		max = 127;
		free(line);
	}
	ft_printf("highest pass id: %d\n", result);
	return (0);
}