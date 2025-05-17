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
	ssize_t		bytes_read;
	char		*buffer;
	char		*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	temp = NULL;
	while (!left_c || (!ft_strchr(left_c, '\n') && bytes_read > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buffer);
			free (temp);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(left_c, buffer);
		if (!temp)
		{
			free (buffer);
			free (left_c);
			return (NULL);
		}
		free(left_c);
		left_c = temp;
	}
	free (buffer);
	if (!left_c || left_c[0] == '\0')
	{
		free(left_c);
		return (NULL);
	}
	return (left_c);
}
/*
static size_t	count_chars(char *str)
{
	size_t	count;
	
	while (str[count] && str[count] != '\n')
		count++;
	if (str[count] == '\n')
		count++;
	return (count);
}
*/
static char	*ft_get_leftover(char *full)
{
	size_t	i;
	char	*leftover;

	if (!full)
		return (NULL);
	i = 0;
	/*if (full[0])
		i = count_chars(full);*/
	while (full[i] && full[i] != '\n')
		i++;
	if (full[i] == '\n')
		i++;
	leftover = ft_substr(full, i, ft_strlen(full) - i);
	if (!leftover)
	{
		free (full);
		return (NULL);
	}
	free (full);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_get_buffer(fd, remainder);
	if (!remainder)
		return (NULL);
	i = 0;
	/*if (remainder[0])
		i = count_chars(remainder);*/
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = ft_substr(remainder, 0, i);
	if (!line)
	{	
		free (remainder);
		remainder = NULL;
		return (NULL);
	}
	remainder = ft_get_leftover(remainder);
	if (!*remainder)
	{
		free (remainder);
		remainder = NULL;
	}
	return (line);
}
