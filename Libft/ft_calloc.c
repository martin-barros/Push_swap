/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:13:14 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/01 22:51:38 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	space;

	if (size != 0 && nmemb >= (((size_t) - 1) / size))
		return (NULL);
	space = nmemb * size;
	ptr = (void *)malloc(space);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, space);
	return (ptr);
}
