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
		bytes_read = read(fd, buffer, BUFFER_SIZE); //buffer is the dest of this read
		if (bytes_read < 0)
		{
			free (buffer);
			free (temp); //do we need to?
			return (NULL);
		}
		buffer[bytes_read] = '\0';//null-terminating
		temp = ft_strjoin(left_c, buffer);//including NULL + buffer
		if (!temp)
		{
			free (buffer);
			return (NULL);
		}
		free(left_c);
		left_c = temp;
	}
	free (buffer); //buffers job done //free (temp);  //do I not need to here???
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*tmp;
	char		*line;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    	remainder = ft_get_buffer(fd, remainder);  //works even whe remainder is emtpyy
	if (!remainder)
		return (NULL);  //NULL includes every type of erros in ft_get_buffer
	i = 0;
	while (remainder[i] && remainder[i] != '\n')  //it goes to every 5 bytes read
		i++;
	i++;   //in the last 5 bytes, only until \n is counted
	line = ft_substr(remainder, 0, i);//find the first line including the tab
	if (!line)
		return (NULL);  //there is malloc in substr, so !line check needed
	tmp = ft_substr(remainder, i, ft_strlen(remainder) - i);
	if (!tmp)
	{
		free(line);
		free(remainder);
		return (NULL);
	}
	free(remainder);  //this remainder job done
	remainder = tmp;  //now  remainder is the left-over bytes from last buffer
	if (!*remainder)  //this check is in case of EOF
	{
		free (remainder);
		remainder = NULL;
	}
	return (line);
}
