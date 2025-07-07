/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:24:02 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/06 00:00:05 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_delete(void *ptr)
{
	if (ptr)
		free(ptr);
}

int	signs(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '+' || s[i] == '-') && s[i] != s[0])
			return (0);
		if ((s[i] == '+' || s[i] == '-') && i - 1 >= 0 && s[i - 1] != ' ')
			return (0);
		if ((s[i] == '+' || s[i] == '-') && i - 1 >= 0 && s[i + 1] &&
				((s[i + 1] == s[i] || s[i - 1] == s[i])))
			return (0);
		if ((s[i] == '+' || s[i] == '-') && s[i] == s[0] && s[i + 1] && (s[i + 1] == s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	repeat_in_out(char *s1, char **s2, int pos, int size)
{
	char	**wd_list;
	int		i;
	int		x;

	wd_list = ft_split(s1, ' ');
	i = 1;
	while (i <= size)
	{
		if (i == pos)
			i++;
		x = 0;
		while (wd_list[x])
		{
			if (ft_strncmp(s2[i], wd_list[x], 11) == 0)
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}
