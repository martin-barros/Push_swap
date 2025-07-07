/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:10:24 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/06 03:54:48 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*swap_a(t_list **head, t_list *two)
{
	t_list	*tmp;

	if (ft_lstsize(*head) < 2)
		return ("sa");
	tmp = two->next;
	ft_lstadd_front(head, two);
	(*head)->next->next = tmp;
	return ("sa");
}

char	*swap_b(t_list **head, t_list *two)
{
	t_list	*tmp;

	if (ft_lstsize(*head) < 2)
		return ("sb");
	tmp = two->next;
	ft_lstadd_front(head, two);
	(*head)->next->next = tmp;
	return ("sb");
}

char	*ss(t_list **head_a, t_list *two_a, t_list **head_b, t_list *two_b)
{
	swap_a(head_a, two_a);
	swap_b(head_b, two_b);
	return ("ss");
}

char	*push_a(t_list **head_dest, t_list **head_src)
{
	t_list	*tmp;

	tmp = (*head_src)->next;
	ft_lstadd_front(head_dest, *head_src);
	*head_src = tmp;
	return ("pa");
}

char	*push_b(t_list **head_dest, t_list **head_src)
{
	t_list	*tmp;

	tmp = (*head_src)->next;
	ft_lstadd_front(head_dest, *head_src);
	*head_src = tmp;
	return ("pb");
}
