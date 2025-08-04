/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:58:32 by mabarros          #+#    #+#             */
/*   Updated: 2025/08/04 12:19:14 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**fail(char **list, size_t size)
{
	while (size--)
		free(list[size]);
	free(list);
	return (NULL);
}

static size_t	ft_how_many(char const *s, char c, char **lst)
{
	size_t	i;
	size_t	size;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		size = 0;
		while (s[size] && s[size] != c)
			size++;
		if (size && lst)
		{
			lst[i] = ft_substr(s, 0, size);
			if (lst[i] == NULL)
				return (fail(lst, i), -1);
		}
		if (size)
			i++;
		s += size;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	how_many_words;
	char	**word_list;

	if (s == NULL)
		return (ft_calloc(sizeof(char *), 1));
	how_many_words = ft_how_many(s, c, NULL);
	word_list = ft_calloc(sizeof(char *), how_many_words + 1);
	if (word_list == NULL)
		return (NULL);
	if (ft_how_many(s, c, word_list) == ((size_t)-1))
		return (NULL);
	return (word_list);
}
