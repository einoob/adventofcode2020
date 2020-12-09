/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ninth_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:33:24 by elindber          #+#    #+#             */
/*   Updated: 2020/12/09 10:33:24 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf/includes/ft_printf.h"
#include "../libftprintf/includes/get_next_line.h"

long		ft_atol(const char *str)
{
	long		res;
	long		sign;

	res = 0;
	sign = 1;
	while (*str && (*str == '\r' || *str == '\n' || *str == '\t' ||
					*str == '\f' || *str == '\v' || *str == ' '))
		str++;
	if (str[0] == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}

long		check_current_number(long *values, int sum, int a, int b)
{
	while (a < sum - 1)
	{
		while (b < sum)
		{
			if (values[a] + values[b] == values[sum])
				return (0);
			b++;
		}
		a++;
		b = a + 1;
	}
	return (values[sum]);
}

long		find_inconsistent_number(long *values)
{
	int		a;
	int		b;
	int		sum;
	int		res;

	sum = 25;
	a = sum - 25;
	b = sum - 24;
	while (values[sum] != -1)
	{
		if ((res = check_current_number(values, sum, a, b)))
			return (res);
		sum++;
		a = sum - 25;
		b = sum - 24;
	}
	return (-1);
}

int		main(int ac, char **av)
{
	long	values[1001];
	char	*line;
	int		fd;
	int		i;

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (-1);
	i = 0;
	while (get_next_line(fd, &line))
	{
		values[i] = ft_atol(line);
		free(line);
		i++;
	}
	values[i] = -1;
	ft_printf("%d\n", find_inconsistent_number(values));
}