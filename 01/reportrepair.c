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

int		main(int ac, char **av)
{
	int		number_list[201];
	int		i;
	int		fd;
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
	}
}