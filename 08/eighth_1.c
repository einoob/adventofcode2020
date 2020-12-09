/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eighth_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:22:43 by elindber          #+#    #+#             */
/*   Updated: 2020/12/08 10:22:43 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"
#include <stdio.h>

long		run_instructions(char **input, int *executions)
{
	int		y;
	long		accumulator;
	int		arg_value;
	int		i;

	y = 0;
	i = 0;
	accumulator = 0;
	while (1)
	{
		printf("\nround %d\n", ++i);
		if (ft_strstr(input[y], "nop"))
		{
			executions[y] += 1;
			arg_value = ft_atoi(&(input[y][4]));
			printf("nop: %d %d %s\n", y, arg_value, input[y]);
			if (executions[y] > 1)
			{
				printf("%d %ld %s\n", y, accumulator, input[y]);
				return (accumulator);
			}
			y++;
		}
		if (ft_strstr(input[y], "acc"))
		{
			arg_value = ft_atoi(&(input[y][4]));
			printf("acc: %d %d %s\n", y, arg_value, input[y]);
			executions[y] += 1;
			if (executions[y] > 1)
			{
				printf("%d %ld %s\n", y, accumulator, input[y]);
				return (accumulator);
			}
			accumulator += ft_atoi(&(input[y][4]));
			y++;
		}
		if (ft_strstr(input[y], "jmp"))
		{
			executions[y] += 1;
			if (executions[y] > 1)
			{
				printf("%d %ld %s\n", y, accumulator, input[y]);
				return (accumulator);
			}
			arg_value = ft_atoi(&(input[y][4]));
			printf("jmp: %d %d %s\n", y, arg_value, input[y]);
			y += ft_atoi(&(input[y][4]));
		}
	}
}

int		main(int ac, char **av)
{
	char	*input[612];
	int		executions[611];
	char	*line;
	int		fd;
	int		y;

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (-1);
	y = -1;
	while (get_next_line(fd, &line))
	{
		input[++y] = ft_strdup(line);
		executions[y] = 0;
		free(line);
	}
	input[y + 1] = NULL;
	executions[y + 1] = -1;
	printf("accuweather: %ld\n", run_instructions(input, executions));
}