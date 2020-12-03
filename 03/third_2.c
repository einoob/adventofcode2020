/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:04:58 by elindber          #+#    #+#             */
/*   Updated: 2020/12/03 12:04:58 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"
#include <stdio.h>

int		navigate(char **array, int x_move, int y_move)
{
	int	y;
	int	x;
	int	row_len;
	int	count;

	x = x_move;
	y = y_move;
	count = 0;
	row_len = ft_strlen(array[0]) - 1;
	while (array[y] != NULL)
	{
		if (array[y][x] == '#')
			count++;
		x = x + x_move >= row_len ? x + x_move - row_len : x + x_move;
		y += y_move;
		if (array[y - 1] == NULL)
			break ;
	}
	ft_printf("crashed: %d\n", count);
	return (count);
}

int		main(int ac, char **av)
{
	char **array;
	char	*line;
	int		fd;
	int		i;
	long 	count;

	i = 0;
	if (ac != 2 || !(array = (char**)malloc(sizeof(char*) * 324)))
		return (-1);
	array[323] = NULL;
	fd = open(av[1], O_RDONLY);
	count = 0;
	while (get_next_line(fd, &line))
	{
		array[i] = ft_strdup(line);
		i++;
		free(line);
	}
	count += navigate(array, 1, 1);
	count *= navigate(array, 3, 1);
	count *= navigate(array, 5, 1);
	count *= navigate(array, 7, 1);
	count *= navigate(array, 1, 2);
	ft_printf("Trees crashed: %ld\n", count);
}
