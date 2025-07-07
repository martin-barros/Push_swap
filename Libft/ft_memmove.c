/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:47:27 by mabarros          #+#    #+#             */
/*   Updated: 2025/04/12 18:06:57 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*p2;
	int				i;

	p2 = (unsigned char *)src;
	ptr = (unsigned char *)dest;
	i = 0;
	if (ptr < p2)
	{
		while (n--)
		{
			ptr[i] = p2[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			ptr[n] = p2[n];
		}
	}
	return (dest);
}
