/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 01:17:15 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/22 18:53:41 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_char_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	parse(char *string, t_list **head)
{
	char	**wd_list;
	int		i;
	int		*ptr;

	i = 0;
	wd_list = ft_split(string, ' ');
	while (wd_list[i] != NULL)
	{
		ptr = malloc(sizeof(int));
		if (!ptr)
		{
			ft_free_char_array(wd_list);
			return (0);
		}
		*ptr = ft_atoi_fixed(wd_list[i]);
		if (!*head)
			*head = ft_lstnew(ptr);
		else
			ft_lstadd_back(head, ft_lstnew(ptr));
		i++;
	}
	ft_free_char_array(wd_list);
	return (1);
}

int	make_stack_a(t_list **head, int argc, char *argv[])
{
	int			i;
	int			*ptr;

	i = 1;
	while (i <= (argc - 1))
	{
		ptr = malloc(sizeof(int));
		if (!ptr)
			return (0);
		if (has_whitespace(argv[i]))
		{
			if (!parse(argv[i++], head))
				return (free(ptr), 0);
			free(ptr);
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
	return (no_repeat((*head)));
}

int	no_repeat(t_list *head)
{
	t_list	*tmp;
	int		*ptr1;
	int		*ptr2;

	while (head->next)
	{
		tmp = head->next;
		ptr1 = head->content;
		head = head->next;
		while (head)
		{
			ptr2 = head->content;
			if (*ptr1 == *ptr2)
				return (0);
			head = head->next;
		}
		head = tmp;
	}
	return (1);
}

int	make_stack_b(t_list **head)
{
	*head = NULL;
	return (1);
}
