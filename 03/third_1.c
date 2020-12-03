/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:37:08 by elindber          #+#    #+#             */
/*   Updated: 2020/12/03 10:37:08 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"

int		navigate(char **array)
{
	int	x;
	int	y;
	int	row_len;
	int	count;

	x = 3;
	y = 0;
	count = 0;
	row_len = ft_strlen(array[0]) - 1;
	while (array[++y] != NULL)
	{
		if (array[y][x] == '#')
			count++;
		x = x + 3 >= row_len ? x + 3 - row_len : x + 3;
	}
	return (count);
}

int		main(int ac, char **av)
{
	char **array;
	char	*line;
	int		fd;
	int		i;
	int		count;

	i = 0;
	if (ac != 2 || !(array = (char**)malloc(sizeof(char*) * 324)))
		return (-1);
	array[323] = NULL;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		array[i] = ft_strdup(line);
		i++;
		free(line);
	}
	count = navigate(array);
	ft_printf("Trees crashed: %d\n", count);
}