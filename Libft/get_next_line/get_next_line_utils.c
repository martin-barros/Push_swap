/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:27:51 by mabarros          #+#    #+#             */
/*   Updated: 2025/06/28 19:21:12 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str && *str != '\n')
	{
		i++;
		str++;
	}
	if (*str == '\n')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2)
{
	char	*result;
	int		lens1;
	int		lens2;

	if (!s2)
		return (NULL);
	if (!s1)
		lens1 = 0;
	else
		lens1 = -1;
	lens2 = -1;
	result = malloc(ft_strnlen(s1) + ft_strnlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	while (s1 && s1[++lens1])
		result[lens1] = s1[lens1];
	while (s2[++lens2] && s2[lens2] != '\n')
		result[lens1 + lens2] = s2[lens2];
	if (s2[lens2] && s2[lens2] == '\n')
	{
		result[lens1 + lens2] = s2[lens2];
		lens2++;
	}
	result[lens1 + lens2] = '\0';
	return (free(s1), result);
}

void	ft_next(char *buffer)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	while (buffer[x])
		buffer[x++] = buffer[i++];
	buffer[x] = '\0';
}

char	*ft_error_read(char *line, char *buffer)
{
	buffer[0] = '\0';
	free(line);
	return (NULL);
}

int	ft_read(int fd, char *buffer, int *i)
{
	*i = read(fd, buffer, BUFFER_SIZE);
	return (*i);
}
