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

long	sum_of_limits(long *values, int start, int end)
{
	long		min;
	long		max;

	min = values[start];
	max = values[start];
	start++;
	while (start <= end)
	{
		if (values[start] > max)
			max = values[start];
		if (values[start] < min)
			min = values[min];
		start++;
	}
	return (max + min);
}

long	find_segment(long *values, int nbr)
{
	int		start;
	int		end;
	long	sum;

	start = 0;
	end = 1;
	while (values[end] != -1)
	{
		sum = values[start] + values[end];
		while (sum < nbr)
		{
			end++;
			sum += values[end];
		//	ft_printf("start, end, sum %d %d %d\n", values[start], values[end], sum);
			if (sum == nbr)
				return (sum_of_limits(values, start, end));
		}
		start++;
		end = start + 1;
		sum = 0;
	}
	return (-1);
}

int		main(int ac, char **av)
{
	long	values[1001];
	char	*line;
	int		fd;
	int		i;
	long		incorrect_number;

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
	incorrect_number = find_inconsistent_number(values);
	ft_printf("incorrect %ld\n", incorrect_number);
	ft_printf("%ld\n", find_segment(values, incorrect_number));
}