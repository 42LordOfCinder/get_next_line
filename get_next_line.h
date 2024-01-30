/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:32:11 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/23 16:52:52 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_line(char *buffer, char *line);
char	*get_next_line(int fd);
#endif
