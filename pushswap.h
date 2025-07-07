/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:12:59 by mabarros          #+#    #+#             */
/*   Updated: 2025/07/07 10:13:27 by mabarros         ###   ########.fr       */
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
int		no_repeat(char **arr, int size);
int		is_int_limit(char **arr, int size);
int		make_stack_a(t_list **head, int argc, char *argv[]);
void	ft_delete(void *ptr);
int		ft_atoi_fixed(const char *nptr);
int		has_whitespace(char	*arr);
int		signs(char *s);
int		repeat_in_out(char *s1, char **s2, int pos, int size);
char	*swap_a(t_list **head, t_list *two);
char	*swap_b(t_list **head, t_list *two);
char	*ss(t_list **head_a, t_list *two_a, t_list **head_b, t_list *two_b);
char	*push_a(t_list **head_dest, t_list **head_src);
int 	make_stack_b(t_list **head);
char	*push_b(t_list **head_dest, t_list **head_src);
char	*rotate_a(t_list **head);
char	*rotate_b(t_list **head);
char	*rr_rrr(t_list **head_a, t_list **head_b, int cmd);

#endif