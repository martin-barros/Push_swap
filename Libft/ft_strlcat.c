/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:51:11 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/01 22:43:32 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	len_dest;

	i = 0;
	x = 0;
	len_dest = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= len_dest)
		return (size + ft_strlen(src));
	size = (size - len_dest - 1);
	while (dst[i])
		i++;
	while (size-- && src[x])
	{
		dst[i++] = src[x];
		x++;
	}
	dst[i] = '\0';
	return (len_dest + ft_strlen(src));
}
