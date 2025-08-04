/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:24:02 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/22 21:38:28 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_delete_new(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	while ((*head_a))
	{
		tmp = (*head_a)->next;
		if (*head_a)
		{
			free((*head_a)->content);
			free((*head_a));
		}
		(*head_a) = tmp;
	}
	while ((*head_b))
	{
		tmp = (*head_b)->next;
		if (*head_b)
			free(*head_b);
		(*head_b) = tmp;
	}
}

int	signs(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '+' || s[i] == '-') && i - 1 >= 0 && s[i - 1] != ' ')
			return (0);
		if ((s[i] == '+' || s[i] == '-') && i - 1 >= 0 && s[i + 1]
			&& ((s[i + 1] == s[i] || s[i - 1] == s[i])))
			return (0);
		if ((s[i] == '+' || s[i] == '-') && s[i] == s[0] && s[i + 1]
			&& (s[i + 1] == s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	string_nums(char *arg)
{
	int		i;
	char	**wd_list;

	i = 0;
	if (!arg)
		return (0);
	wd_list = ft_split(arg, ' ');
	while (wd_list[i])
	{
		if (i > 0)
		{
			ft_free_char_array(wd_list);
			return (1);
		}
		i++;
	}
	ft_free_char_array(wd_list);
	return (0);
}
