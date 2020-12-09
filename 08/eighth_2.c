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

void		swap_instructions(char *line)
{
	if (line[0] == 'j')
		line[0] = 'n';
	else if (line[0] == 'n')
		line[0] = 'j';
	if (line[1] == 'm')
		line[1] = 'o';
	else if (line[1] == 'o')
		line[1] = 'm';
}

void		reset_executions(int *execs)
{
	int		i;

	i = -1;
	while (execs[++i] >= 0)
	{
		execs[i] = 0;
	}
}

long		run_instructions(char **input, int *executions)
{
	int		y;
	long	accumulator;

	y = 0;
	accumulator = 0;
	while (input[y] != NULL)
	{
		if (ft_strstr(input[y], "nop"))
		{
			executions[y] += 1;
			if (executions[y] > 99)
				return (-12345);
			y++;
			if (input[y] == NULL)
				return (accumulator);
		}
		if (ft_strstr(input[y], "acc"))
		{
			executions[y] += 1;
			if (executions[y] > 99)
				return (-12345);
			accumulator += ft_atoi(&(input[y][4]));
			y++;
			if (input[y] == NULL)
				return (accumulator);
		}
		if (ft_strstr(input[y], "jmp"))
		{
			executions[y] += 1;
			if (executions[y] > 99)
				return (-12345);
			y += ft_atoi(&(input[y][4]));
			if (input[y] == NULL)
				return (accumulator);
		}
	}
	return (accumulator);
}

long 		fix_code(char **input, int *executions)
{
	int		y;
	int		result;

	y = -1;
	result = -12345;
	while (input[++y] != NULL)
	{
	//	ft_printf("fixing... %d\n", y);
		if (ft_strstr(input[y], "jmp"))
		{
			swap_instructions(input[y]);
			result = run_instructions(input, executions);
			swap_instructions(input[y]);
		}
		else if (ft_strstr(input[y], "nop"))
		{
			swap_instructions(input[y]);
			result = run_instructions(input, executions);
			swap_instructions(input[y]);
		}
		if (result != -12345)
			return (result);
		reset_executions(executions);
	}
	return (-12345);
}

int			main(int ac, char **av)
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
	ft_printf("%d\n", fix_code(input, executions));
}