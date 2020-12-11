/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenth_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:39:51 by elindber          #+#    #+#             */
/*   Updated: 2020/12/10 10:39:51 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"

int		good_ol_bubble_sort(int *nbrs)
{
	int		i;
	int		swap;

	i = 0;
	while (nbrs[++i] != -1)
	{
		if (nbrs[i] < nbrs[i - 1])
		{
			swap = nbrs[i];
			nbrs[i] = nbrs[i - 1];
			nbrs[i - 1] = swap;
			i = 0;
		}
	}
	return (nbrs[i - 1] + 3);
}

long long	routes_to_goalsz(int *nbrs, int goal, int i, int count, int incre)
{
	while (nbrs[i] != goal)
	{
		if (nbrs[i])
	}
}

int		main(int ac, char **av)
{
	char			*line;
	int				nbrs[101];
	int				fd;
	long long	i;
	int				goalsz;

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (-1);
	i = 0;
	nbrs[i] = 0;
	while (get_next_line(fd, &line))
	{
		nbrs[++i] = ft_atoi(line);
		free(line);
	}
	nbrs[i] = -1;
	goalsz = good_ol_bubble_sort(nbrs);
	ft_printf("goalsz %d\n", goalsz);
	i = -1;
//	while (nbrs[++i] != -1)
//		ft_printf("%d\n", nbrs[i]);
	i = routes_to_goalsz(nbrs, goalsz, 0, 0, 0);
	ft_printf("%lld\n", i);
}