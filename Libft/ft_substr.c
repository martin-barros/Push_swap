/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:48:24 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/01 22:38:40 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (len + start >= ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (len--)
		ptr[i++] = (char)s[start++];
	ptr[i] = '\0';
	return (ptr);
}
