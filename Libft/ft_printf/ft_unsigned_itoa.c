/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:30:01 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/16 19:47:53 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_get_size(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_ptr(char *result, unsigned int n, unsigned int size)
{
	if (n == 0)
	{
		*result = '0';
		return ;
	}
	while (size && n)
	{
		result[--size] = (char)((n % 10) + 48);
		n /= 10;
	}
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*result;
	unsigned int	size;

	size = ft_get_size(n);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	ft_putnbr_ptr(result, n, size);
	result[size] = '\0';
	return (result);
}
