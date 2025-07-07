/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:22:31 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/16 19:48:03 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	size_t	address;
	int		count;

	count = 0;
	address = (size_t)ptr;
	if (!ptr)
		return (ft_putlstr("(nil)"));
	count += ft_putlstr("0x");
	count += ft_x(address, 'x');
	return (count);
}
