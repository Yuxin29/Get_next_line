/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:19:06 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/16 12:41:16 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
notes of new things used in get_next_line
- ssize_t: signed versiong of size_t(unsigned)
- read(fd, buffer, max): a bit like printf, returns(+, 0(EOF), -(error));
*/

#include "get_next_line.h"

static char	*ft_get_buffer(int fd, char *left_c)
{
	ssize_t		bytes_read;//output of read
	char		*buffer;
	char		*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!left_c || (!ft_strchr(left_c, '\n') && bytes_read > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buffer);
			free (temp);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(left_c, buffer);
		if (!temp)
		{
			free (buffer);
			return (NULL);
		}
		free(left_c);
		left_c = temp;
	}
	free (buffer);
	return (left_c);
}

static char *ft_get_leftover(char *full)
{
	int	i;
	char	*tmp;
	
	i = 0;
	while (full[i] && full[i] != '\n')
		i++;
	i++;
	tmp = ft_substr(full, i, ft_strlen(full) - i);
	if (!tmp)
	{
		free(full);
		return (NULL);
	}
	full = tmp;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    	remainder = ft_get_buffer(fd, remainder);
	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	i++;
	line = ft_substr(remainder, 0, i);
	if (!line)
		return (NULL);
	remainder = ft_get_leftover(remainder);
	if (!*remainder)
	{
		free (remainder);
		remainder = NULL;
	}
	return (line);
}
