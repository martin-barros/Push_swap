/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:30:44 by marvin            #+#    #+#             */
/*   Updated: 2025/07/08 19:30:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    move_index(t_list *head, int index)
{
    ft_lstlast(*head)->index = index;
    while (*head->next)
    {
        if (*head->index >= index)
            *head->index++;
        *head = (*head)->next;
    }
}

void    sort_index(t_list *head)
{
    int i;
    int *ptr1;
    int *ptr2;

    i = 0;
    if (ft_lstsize(*head) <= 1)
        (*head)->index = 1;
    else
    {
        while (*head)
        {
            ptr1 = (*head)->content;
            ptr2 = ft_lstlast(*head)->content;
            if (*ptr1 > *ptr2)
            {
                i++;
                break;
            }
            *head = (*head)->next;
        }
        if (i)
            move_index(head, *head->index);
    }
}
