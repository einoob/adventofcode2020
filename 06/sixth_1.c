/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixth_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:32:26 by elindber          #+#    #+#             */
/*   Updated: 2020/12/06 11:32:26 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"

int		add_to_total(int *answers)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < 26)
		count += answers[i];
	return (count);
}

void	reset_answers(int *answers)
{
	int		i;

	i = -1;
	while (++i < 26)
		answers[i] = 0;
}

int		main(int ac, char **av)
{
	int		answers[26];
	int		i;
	int		count;
	int		fd;
	char	*line;

	i = -1;
	count = 0;
	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	reset_answers(answers);
	while (get_next_line(fd, &line))
	{
		while (ft_isalpha(ft_tolower(line[++i])))
		{
			answers[line[i] - 97] = 1;
		}
		if (ft_strlen(line) == 1 || line[0] == '\n')
		{
			count += add_to_total(answers);
			reset_answers(answers);
			i = -1;
		}
		free(line);
		i = -1;
	}
	ft_printf("total: %d\n", count);
}