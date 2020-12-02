/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:03:32 by elindber          #+#    #+#             */
/*   Updated: 2020/12/02 10:03:32 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"


int		main(int ac, char **av)
{
	char	*line;
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
		while (line[++i] != '\0')
		{
			if (line[i] == to_find)
				count++;
		}
		if (count >= min && count <= max)
			result++;
		i = 0;
		count = 0;
		free(line);
	}
	close(fd);
	ft_printf("Amount of valid passwordsz: %d\n", result);
	system("leaks a.out");
	return (0);
}
