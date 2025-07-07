/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:00:33 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/01 22:31:57 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_get_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_ptr(char *result, int n, int size)
{
	if (n == 0)
	{
		*result = '0';
		return ;
	}
	if (n < 0)
	{
		*result = '-';
		n *= -1;
	}
	while (size && n)
	{
		result[--size] = (char)((n % 10) + 48);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_get_size(n);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	ft_putnbr_ptr(result, n, size);
	result[size] = '\0';
	return (result);
}
