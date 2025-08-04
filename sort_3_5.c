/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:01:55 by mabarros          #+#    #+#             */
/*   Updated: 2025/08/04 12:24:48 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_list **head)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = (*head)->index;
	val2 = (*head)->next->index;
	val3 = (*head)->next->next->index;
	if (is_sorted(*head))
		return ;
	if (val1 > val2 && val1 > val3)
		rotate_a(head);
	else if (val2 > val1 && val2 > val3)
		rrotate_a(head);
	if ((*head)->index > (*head)->next->index)
		swap_a(head);
}

static void	place_4(t_list **head_a, t_list **head_b)
{
	if ((*head_b)->index < (*head_a)->index)
		push_a(head_a, head_b);
	else if (((*head_b)->index > (*head_a)->index)
		&& ((*head_b)->index < (*head_a)->next->index))
	{
		push_a(head_a, head_b);
		swap_a(head_a);
	}
	else if (((*head_b)->index > (*head_a)->next->index)
		&& ((*head_b)->index < (*head_a)->next->next->index))
	{
		rrotate_a(head_a);
		push_a(head_a, head_b);
		rotate_a(head_a);
		rotate_a(head_a);
	}
	else
	{
		push_a(head_a, head_b);
		rotate_a(head_a);
	}
}

static void	troublesome_case(t_list **head_a, t_list **head_b)
{
	rotate_a(head_a);
	push_a(head_a, head_b);
	swap_a(head_a);
	rrotate_a(head_a);
}

static void	place_5(t_list **head_a, t_list **head_b)
{
	if ((*head_b)->index < (*head_a)->index)
		push_a(head_a, head_b);
	else if (((*head_b)->index > (*head_a)->index)
		&& ((*head_b)->index < (*head_a)->next->index))
	{
		push_a(head_a, head_b);
		swap_a(head_a);
	}
	else if (((*head_b)->index > (*head_a)->next->index)
		&& ((*head_b)->index < (*head_a)->next->next->index))
		troublesome_case(head_a, head_b);
	else if (((*head_b)->index > (*head_a)->next->next->index)
		&& ((*head_b)->index < (*head_a)->next->next->next->index))
	{
		rrotate_a(head_a);
		push_a(head_a, head_b);
		rotate_a(head_a);
		rotate_a(head_a);
	}
	else
	{
		push_a(head_a, head_b);
		rotate_a(head_a);
	}
}

void	sort_5(t_list **head_a, t_list **head_b)
{
	if (is_sorted(*head_a))
		return ;
	push_b(head_b, head_a);
	push_b(head_b, head_a);
	sort_3(head_a);
	place_4(head_a, head_b);
	place_5(head_a, head_b);
}
