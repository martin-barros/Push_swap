/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:29:20 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/01 22:38:35 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_front(char const *s1, char const *set)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (set[x] && s1[i])
	{
		if (s1[i] != set[x])
			x++;
		else
		{
			i++;
			x = 0;
		}
	}
	return (i);
}

static int	ft_size_back(char const *s1, char const *set)
{
	int		i;
	int		x;
	size_t	size;
	int		result;

	size = ft_strlen(s1);
	i = size - 1;
	x = 0;
	result = 0;
	while (set[x] && size)
	{
		if (s1[i] != set[x])
			x++;
		else
		{
			i--;
			x = 0;
			size--;
			result++;
		}
	}
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		size;

	if (!s1 || !set)
		return (NULL);
	s1 += ft_check_front(s1, set);
	if (*s1 == '\0')
		return (ft_strdup(""));
	size = ft_strlen(s1) - ft_size_back(s1, set);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (size--)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
