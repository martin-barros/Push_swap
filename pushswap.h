/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:12:59 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/26 23:36:24 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "Libft/libft.h"

int		only_digits(char **arr, int size);
int		no_repeat(t_list *head);
int		is_int_limit(char **arr, int size);
int		make_stack_a(t_list **head, int argc, char *argv[]);
void	ft_delete_new(t_list **head_a, t_list **head_b);
int		ft_atoi_fixed(const char *nptr);
int		has_whitespace(char	*arr);
int		signs(char *s);
void	push_a(t_list **head_dest, t_list **head_src);
int		make_stack_b(t_list **head);
void	push_b(t_list **head_dest, t_list **head_src);
void	rotate_a(t_list **head);
void	sort_index(t_list *head, t_list *node_index);
void	sort(t_list **head_a, t_list **head_b, int maxbits);
int		bits(t_list *head);
int		string_nums(char *arg);
int		is_sorted(t_list *head);
void	ft_free_char_array(char **arr);
void	swap_a(t_list **head);
void	sort_3(t_list **head);
void	sort_5(t_list **head_a, t_list **head_b);
void	rrotate_a(t_list **head);

#endif