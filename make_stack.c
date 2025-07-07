/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 01:17:15 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/06 03:38:32 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int parse(char *string, t_list **head)
{
	char	**wd_list;
	int		i;

	i = 0;
	wd_list = ft_split(string, ' ');
	while (wd_list[i] != NULL)
	{
		int		*ptr;

		ptr = malloc(sizeof(int));
		if (!ptr)
			return (0);
		*ptr = ft_atoi_fixed(wd_list[i]);
		if (!*head)
			*head = ft_lstnew(ptr);
		else
			ft_lstadd_back(head, ft_lstnew(ptr));
		i++;
	}
	return (1);
}

int	make_stack_a(t_list **head, int argc, char *argv[])
{
	int			i;
	int			*ptr;
	char	**wd_list;

	i = 1;
	while (i <= (argc - 1))
	{
		ptr = malloc(sizeof(int));
		if (!ptr)
			return (0);
		if (has_whitespace(argv[i]))
		{
			if(!parse(argv[i++], head))
				return (0);
		}
		else
		{
			*ptr = ft_atoi_fixed(argv[i++]);
			if (!*head)
				*head = ft_lstnew(ptr);
			else
				ft_lstadd_back(head, ft_lstnew(ptr));
		}
	}
	return (wd_list = NULL, 1);
}

int make_stack_b(t_list **head)
{
	*head = ft_lstnew(NULL);
	if (!(*head))
		return (0);
	return (1);
}