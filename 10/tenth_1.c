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

void	good_ol_bubble_sort(int *nbrs)
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
}

long	count_differences(int *nbrs)
{
	int		i;
	int		ones;
	int		threes;

	i = 0;
	ones = 0;
	threes = 0;
	while (nbrs[++i] != -1)
	{
		if (nbrs[i - 1] + 1 == nbrs[i])
		{
			ft_printf("ONE %d %d\n", nbrs[i - 1], nbrs[i]);
			ones++;
		}
		else if (nbrs[i - 1] + 3 == nbrs[i])
		{
			ft_printf("THREE %d %d\n", nbrs[i - 1], nbrs[i]);
			threes++;
		}
	}
	threes++;
	ft_printf("ones %d threes %d\n", ones, threes);
	return (ones * threes);
}

int		main(int ac, char **av)
{
	char	*line;
	int		nbrs[101];
	int		fd;
	int		i;

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
	good_ol_bubble_sort(nbrs);
	i = -1;
	while (nbrs[++i] != -1)
		ft_printf("%d\n", nbrs[i]);
	ft_printf("%ld\n", count_differences(nbrs));
}