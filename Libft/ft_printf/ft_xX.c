/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:01:32 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/16 22:51:08 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x(size_t n, char type)
{
	char	*hex_base;
	int		count;

	count = 0;
	if (type == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_x(n / 16, type);
	count += ft_putchar_count(hex_base[n % 16]);
	return (count);
}
