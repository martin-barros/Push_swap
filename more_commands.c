/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:56:29 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/06 05:25:10 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*rotate_a(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*head)->next;
	tmp2 = *head;
	*head = tmp;
	tmp2->next = NULL;
	ft_lstlast(*head)->next = tmp2;
	return ("ra");
}

char	*rotate_b(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*head)->next;
	tmp2 = *head;
	*head = tmp;
	tmp2->next = NULL;
	ft_lstlast(*head)->next = tmp2;
	return ("rb");
}

char	*rr_rrr(t_list **head_a, t_list **head_b, int cmd)
{
	if (cmd == 0)
	{
		rotate_a(head_a);
		rotate_b(head_b);
		return ("rr");
	}
	else 
	{
		reverse_rotate_a(head_a);
		reverse_rotate_b(head_b);
		return ("rrr");
	}
}

char	*reverse_rotate_a(t_list **head)
{
	ft_lstadd_front(head, ft_lstlast(*head));
	ft_lstlast(*head)->next = NULL;
	return ("rra");
}

char	*reverse_rotate_b(t_list **head)
{
	ft_lstadd_front(head, ft_lstlast(*head));
	ft_lstlast(*head)->next = NULL;
	return ("rrb");
}
