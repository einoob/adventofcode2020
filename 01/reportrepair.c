/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reportrepair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:54:08 by elindber          #+#    #+#             */
/*   Updated: 2020/12/01 11:54:08 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"

long	quick_maths(int *number_list)
{
	int		a;
	int		b;

	a = -1;
	b = 1;
	while (++a < 200)
	{
		while (b < 200)
		{
			if (number_list[a] + number_list[b] == 2020)
			{
				ft_printf("%d %d %d\n", number_list[a], number_list[b], number_list[a] + number_list[b]);
				return (number_list[a] * number_list[b]);
			}
			b++;
		}
		b = a + 2;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		number_list[201];
	int		i;
	int		fd;
	long	code;
	char	*line;

	i = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			number_list[i] = ft_atoi(line);
			free(line);
			i++;
		}
		number_list[i] = -1;
	}
	code = quick_maths(number_list);
	ft_printf("%d\n", code);
}