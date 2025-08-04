/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:10:24 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/26 23:19:32 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(t_list **head_dest, t_list **head_src)
{
	t_list	*tmp;

	if (!(*head_src))
		ft_printf("pa\n");
	tmp = *head_src;
	*head_src = (tmp)->next;
	tmp->next = NULL;
	ft_lstadd_front(head_dest, tmp);
	ft_printf("pa\n");
}

void	push_b(t_list **head_dest, t_list **head_src)
{
	t_list	*tmp;

	if (!(*head_src))
		ft_printf("pb\n");
	tmp = *head_src;
	*head_src = (tmp)->next;
	tmp->next = NULL;
	ft_lstadd_front(head_dest, tmp);
	ft_printf("pb\n");
}

void	rotate_a(t_list **head)
{
	t_list	*tmp;

	if (!(*head))
		ft_printf("ra\n");
	tmp = *head;
	*head = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(head, tmp);
	ft_printf("ra\n");
}

void	swap_a(t_list **head)
{
	t_list	*tmp;

	if (!(*head))
		ft_printf("sa\n");
	tmp = (*head)->next;
	(*head)->next = (*head)->next->next;
	ft_lstadd_front(head, tmp);
	ft_printf("sa\n");
}

void	rrotate_a(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*head))
		ft_printf("rra\n");
	tmp = *head;
	last = ft_lstlast(*head);
	while ((*head)->next->next)
		(*head) = (*head)->next;
	(*head)->next = NULL;
	*head = tmp;
	ft_lstadd_front(head, last);
	ft_printf("rra\n");
}
