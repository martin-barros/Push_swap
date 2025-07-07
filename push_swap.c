/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:11:45 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/06 04:32:23 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int	is_sorted(int *arr, int size)
// {
// 	int i;
// 	int x;

// 	i = 1;
// 	x = i + 1;
// 	while (x <= size)
// 	{
// 		if (arr[i] > arr[x])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

static int	do_protections(int argc, char *argv[])
{
	if (!(only_digits(argv, argc - 1)))
		return (ft_printf("Error\n"), 0);
	if (!(is_int_limit(argv, argc - 1)) || !(no_repeat(argv, argc - 1)))
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int		*test;
	static t_list	*head_a;
	static t_list	*head_b;

	i = 1;
	if (argc < 3)
		return (-1);
	if (!do_protections(argc, argv))
		return (-1);
	if (!make_stack_a(&head_a, argc, argv) || !make_stack_b(&head_b))
		return (ft_lstclear(&head_a, ft_delete), ft_printf("Error\n"), -1);
	test = malloc(sizeof(int));
	test = head_a->content;
	ft_printf("before: %i\n", *test);
	test = ft_lstlast(head_a)->content;
	ft_printf("before: %i\n", *test);
	rotate_a(&head_a);
	test = head_a->content;
	ft_printf("after: %i\n", *test);
	test = ft_lstlast(head_a)->content;
	ft_printf("after: %i\n", *test);
	return (0);
}
