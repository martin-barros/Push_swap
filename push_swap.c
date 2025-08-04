/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:11:45 by mabarros          #+#    #+#             */
/*   Updated: 2025/08/04 12:20:45 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	do_protections(int argc, char *argv[])
{
	if (!(only_digits(argv, argc - 1)))
		return (0);
	if (!(is_int_limit(argv, argc - 1)))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	static t_list	*head_a;
	static t_list	*head_b;
	t_list			*tmp;

	if (!do_protections(argc, argv))
		return (write(2, "Error\n", 6), -1);
	if (argc < 3 && !string_nums(argv[1]))
		return (-1);
	if (!make_stack_a(&head_a, argc, argv) || !make_stack_b(&head_b))
		return (ft_delete_new(&head_a, &head_b), write(2, "Error\n", 6), -1);
	tmp = head_a;
	while (tmp)
	{
		sort_index(head_a, tmp);
		tmp = tmp->next;
	}
	if (ft_lstsize(head_a) == 3)
		sort_3(&head_a);
	else if (ft_lstsize(head_a) == 5)
		sort_5(&head_a, &head_b);
	else
		sort(&head_a, &head_b, bits(head_a));
	ft_delete_new(&head_a, &head_b);
	return (0);
}
