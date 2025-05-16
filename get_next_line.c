/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:19:06 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/16 12:02:02 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_buffer(int fd, char *left_c)
{
	ssize_t bytes_read; //ssize_t: signed versiong of size_t(unsigned)
	char	*buffer;
	char    *temp;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
    while (!left_c || (!ft_strchr(left_c, '\n') && bytes_read > 0))
    {
    	bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buffer);
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

char	*ft_get_line(int fd)
{
	char	*line;

	line = ft_get_buffer(fd, NULL);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char	*remainder;
	ssize_t		bytes_already_read;
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line_buffer)
		return (NULL);
	line = ft_get_line(buffer);
	bytes_already_read = 1;
	remainder = ft_get_line(line);
	while (remainder != NULL)
	{
		bytes_already_read = read(fd, buffer, BUFFER_SIZE);
		remainder = ft_get_line(line);
	}
	return (line);
}

//Use a static variable remainder to hold leftover data between calls.
//Call ft_get_line(fd, remainder, buffer) to update remainder with fresh data.
//If remainder is NULL (error or EOF), return NULL.
//Extract the next line by cleft_calling ft_get_line(remainder).
//Update remainder by removing the returned line from it (leftover management).:
//Return the extracted line.

/* Below are notes
- Return each line including the newline.
- Maintain leftover buffer data between calls(Static variable)
*/
