/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:49:42 by mabarros          #+#    #+#             */
/*   Updated: 2025/05/16 19:49:42 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_putlstr(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_x(size_t n, char type);
int		ft_putptr(void *ptr);
int		ft_putchar_count(int c);

#endif