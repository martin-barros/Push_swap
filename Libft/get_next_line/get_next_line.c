/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:27:22 by mabarros          #+#    #+#             */
/*   Updated: 2025/06/28 19:20:56 by mabarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	storage[BUFFER_SIZE + 1];
	char		*result;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	while (*storage || ft_read(fd, storage, &i) > 0)
	{
		if (i == -1)
			break ;
		result = ft_strnjoin(result, storage);
		if (!result)
			return (NULL);
		ft_next(storage);
		if (result[ft_strnlen(result) - 1] == '\n')
			return (result);
	}
	if (i == -1)
		return (ft_error_read(result, storage));
	return (result);
}
