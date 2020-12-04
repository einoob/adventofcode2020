/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:01:42 by elindber          #+#    #+#             */
/*   Updated: 2020/12/04 10:01:42 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		count;
	int		result;
	int 	y;
	char	**input;
	char	*line;

	count = 0;
	y = 0;
	result = 0;
	fd = open(av[1], O_RDONLY);
	if (ac != 2 || !(input = (char**)malloc(sizeof(char*) * 960)))
		return (-1);
	input[959] = NULL;
	while (get_next_line(fd, &line))
	{
		input[y] = ft_strdup(line);
		free(line);
		y++;	
	}
	y = -1;
	while (input[++y] != NULL)
	{
		if (ft_strstr(input[y], "byr:"))
			count++;
		if (ft_strstr(input[y], "iyr:"))
			count++;
		if (ft_strstr(input[y], "eyr:"))
			count++;
		if (ft_strstr(input[y], "hgt:"))
			count++;
		if (ft_strstr(input[y], "hcl:"))
			count++;
		if (ft_strstr(input[y], "ecl:"))
			count++;
		if (ft_strstr(input[y], "pid:"))
			count++;
		if (ft_strlen(input[y]) == 1 || input[y + 1] == NULL)
		{
			result += count >= 7 ? 1 : 0;
			count = 0;
		}
	}
	ft_printf("valid passports: %d\n", result);
	return (0);
}