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
#include <string.h>

void	free_2d_array(char **array)
{
	int		y;

	y = -1;
	while (array[++y] != NULL)
	{
		free(array[y]);
	}
}

int		check_pid(char **pair)
{
	int		i;

	i = 0;
	while (ft_isdigit(pair[1][i]))
		i++;
	return (i == 9);
}

int		check_ecl(char **pair)
{
	char	*color;
	color = ft_strsub(pair[1], 0, 3);
	if (strcmp(color, "amb") == 0)
		return (1);
	else if (strcmp(color, "blu") == 0)
		return (1);
	else if (strcmp(color, "brn") == 0)
		return (1);
	else if (strcmp(color, "gry") == 0)
		return (1);
	else if (strcmp(color, "grn") == 0)
		return (1);
	else if (strcmp(color, "hzl") == 0)
		return (1);
	else if (strcmp(color, "oth") == 0)
		return (1);
	return (0);
}

int		check_hcl(char **pair)
{
	int		i;

	i = 1;
	if (pair[1][0] != '#')
		return (0);
	while (ft_isdigit(pair[1][i]) || (pair[1][i] >= 'a' && pair[1][i] <= 'f'))
		i++;
	return (i == 7);
}

int		check_hgt(char **pair)
{
	int		height;

	height = ft_atoi(pair[1]);
	if (ft_strstr(pair[1], "cm"))
		return (height >= 150 && height <= 193);
	else if (ft_strstr(pair[1], "in"))
		return (height >= 59 && height <= 76);
	return (0);
}

int		check_eyr(char **pair)
{
	int		year;

	year = ft_atoi(pair[1]);
	return (year >= 2020 && year <= 2030);
}

int		check_iyr(char **pair)
{
	int		year;

	year = ft_atoi(pair[1]);
	return (year >= 2010 && year <= 2020);
}

int		check_byr(char **pair)
{
	int		year;

	year = ft_atoi(pair[1]);
	return (year >= 1920 && year <= 2002);
}

int		check_validness(char *line)
{
	char	**data;
	char	**pair;
	int		count;
	int		y;

	y = 0;
	count = 0;
	if (ft_strchr(line, ' '))
		data = ft_strsplit(line, ' ');
	else
	{
		data = (char**)malloc(sizeof(char*) * 2);
		data[0] = ft_strdup(line);
		data[1] = NULL;
	}
	while (data[y] != NULL)
	{
	//	printf("%s-->\n", data[y]);
		pair = ft_strsplit(data[y], ':');
	//	printf("%s %s\n", pair[0], pair[1]);
		if (ft_strstr(pair[0], "byr"))
			count += check_byr(pair);
		if (ft_strstr(pair[0], "iyr"))
			count += check_iyr(pair);
		if (ft_strstr(pair[0], "eyr"))
			count += check_eyr(pair);
		if (ft_strstr(pair[0], "hgt"))
			count += check_hgt(pair);
		if (ft_strstr(pair[0], "hcl"))
			count += check_hcl(pair);
		if (ft_strstr(pair[0], "ecl"))
			count += check_ecl(pair);
		if (ft_strstr(pair[0], "pid"))
			count += check_pid(pair);
		free_2d_array(pair);
		y++;
	}
	free_2d_array(data);
//	printf("count: %d\n", count);
	return (count);
}

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
		printf("%s\n", input[y]);
		if (ft_strlen(input[y]) > 1)
			count += check_validness(input[y]);
		if (ft_strlen(input[y]) == 1 || input[y + 1] == NULL)
		{
			result += count >= 7 ? 1 : 0;
			if (count >= 7)
				ft_printf("VALID: %d %d\n---------------------\n", count, result);
			else
				ft_printf("INVALID: %d %d\n---------------------\n", count, result);
			count = 0;
		}
	}
	ft_printf("valid passports: %d\n", result);
	return (0);
}