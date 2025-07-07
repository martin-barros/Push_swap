/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:36:12 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/01 23:14:48 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (!little[0])
		return ((char *) big);
	if (len <= 0)
		return (NULL);
	while (big[i] && i < len)
	{
		x = 0;
		while (big[i + x] == little[x] && big[i + x]
			&& little[x] && i + x < len)
		{
			x++;
			if (little[x] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (0);
}
