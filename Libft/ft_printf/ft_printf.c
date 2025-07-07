/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:14:57 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/11 12:15:16 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(const char *type, va_list ap)
{
	char	*string;
	int		count;

	if (*type == 'c')
		return (ft_putchar_count(va_arg(ap, int)));
	else if (*type == '%')
		return (ft_putchar_count('%'));
	else if (*type == 's')
		return (ft_putlstr(va_arg(ap, char *)));
	else if (*type == 'i' || *type == 'd')
		return (string = ft_itoa(va_arg(ap, int)),
			count = ft_putlstr(string), free(string), count);
	else if (*type == 'u')
		return (string = ft_unsigned_itoa(va_arg(ap, unsigned int)),
			count = ft_putlstr(string), free(string), count);
	else if (*type == 'x' || *type == 'X')
		return (ft_x(va_arg(ap, unsigned int), *type));
	else if (*type == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	string = NULL;
	return (count = 0, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	va_start(ap, format);
	count = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_print_type(&format[i + 1], ap);
			i += 2;
		}
		else
			count += write(1, &format[i++], 1);
	}
	va_end(ap);
	if (count < 0)
		return (-1);
	return (count);
}
