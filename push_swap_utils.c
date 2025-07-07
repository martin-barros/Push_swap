/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:18:58 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/06 04:36:28 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	has_whitespace(char	*arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if ((arr[i] >= 9 && arr[i] <= 13) || arr[i] == 32)
			return (1);
		i++;
	}
	return (0);
}

int	is_int_limit(char **arr, int size)
{
	int i;

	i = 1;
	if (size <= 0)
		return (0);
	while (i <= size)
	{
		if (ft_atoi_fixed(arr[i]) == 0 && arr[i][0] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	only_digits(char **arr, int size)
{
	int	i;
	int	x;

	i = 1;
	if (size <= 0)
		return (0);
	while (i <= size )
	{
		x = 0;
		if (!signs(arr[i]))
			return (0);
		while (arr[i][x])
		{
			if (!ft_isdigit(arr[i][x]) && arr[i][x] != '-' && arr[i][x] != '+' 
				&& arr[i][x] != ' ')
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	no_repeat(char **arr, int size)
{
	int i;
	int x;

	i = 1;
	if (size <= 0)
		return (0);
	while (i < size)
	{
		x = i + 1;
		if (has_whitespace(arr[i]))
		{
			if (!repeat_in_out(arr[i], arr, i, size))
				return (0);
		}
		while (x <= size)
		{
			if (ft_atoi_fixed(arr[i]) == ft_atoi_fixed(arr[x]))
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_fixed(const char *nptr)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - 48);
		if ((result > 2147483647 && sign != -1) || result > 2147483648)
			return (0);
		i++;
	}
	return ((int)result * sign);
}
