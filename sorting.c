/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:25:56 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/21 19:00:02 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_index(t_list *head, t_list *node_index)
{
	int		i;
	int		*ptr1;
	int		*ptr2;

	i = 0;
	ptr1 = node_index->content;
	while (head)
	{
		ptr2 = head->content;
		if (*ptr1 > *ptr2)
			i++;
		head = head->next;
	}
	node_index->index = i;
}

int	is_sorted(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		if (i != head->index)
			return (0);
		i++;
		head = head->next;
	}
	return (1);
}

int	bits(t_list *head)
{
	int	i;
	int	value;

	i = 0;
	value = (ft_lstsize(head) - 1);
	while (value > 0)
	{
		value >>= 1;
		i++;
	}
	return (i);
}

void	sort(t_list **head_a, t_list **head_b, int bits)
{
	int	i;
	int	x;
	int	size;
	int	index;

	size = ft_lstsize(*head_a);
	i = 0;
	while (i < bits)
	{
		if (is_sorted((*head_a)))
			break ;
		x = 0;
		while (x++ < size)
		{
			index = (*head_a)->index;
			if (((index >> i) & 1) == 1)
				rotate_a(head_a);
			else
				push_b(head_b, head_a);
		}
		while ((*head_b))
			push_a(head_a, head_b);
		i++;
	}
}
