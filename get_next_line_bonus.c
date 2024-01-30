/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:31:54 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/23 17:45:38 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			chars;

	line = ft_calloc(1, 1);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, 1);
	while (buffer[fd] && line)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_check_line(buffer[fd], line))
			return (line);
		chars = read(fd, buffer[fd], BUFFER_SIZE);
		if (chars <= 0)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
			if (line[0] != 0)
				return (line);
			free(line);
			return (NULL);
		}
		buffer[fd][chars] = 0;
	}
	return (NULL);
}
