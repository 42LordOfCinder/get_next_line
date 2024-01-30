/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:31:54 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/23 17:44:01 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			chars;

	line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	while (buffer && line)
	{
		line = ft_strjoin(line, buffer);
		if (ft_check_line(buffer, line))
			return (line);
		chars = read(fd, buffer, BUFFER_SIZE);
		if (chars <= 0)
		{
			free(buffer);
			buffer = NULL;
			if (line[0] != 0)
				return (line);
			free(line);
			return (NULL);
		}
		buffer[chars] = 0;
	}
	return (NULL);
}
