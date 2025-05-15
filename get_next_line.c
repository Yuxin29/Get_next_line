/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:19:06 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/15 14:33:08 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char	*line_buffer)
{
	ft_strjoin(seved, line_buffer);
}

char	*ft_get_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	bytes_read;	//ssize_t: signed versiong of size_t(unsigned)
    	char	*tmp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))
    	bytes_read = 1;:
    	while (!ft_strchr(left_c, '\n') && (bytes_read) > 0)
    	{
    		buffer = ft_substr(left_c, 0, 5);
    	}
    	ft_strjoin*(
    	return (buffer);
}

char	*ft_get_next_line(int fd)
{
	static char	*remainder;
	//Use a static variable remainder to hold leftover data between calls.
	//Call ft_fill_line_buffer(fd, remainder, buffer) to update remainder with fresh data.
	//If remainder is NULL (error or EOF), return NULL.
	//Extract the next line by calling ft_get_line(remainder).
	//Update remainder by removing the returned line from it (leftover management).:
	//Return the extracted line.
}

char buffer[BUFFER__SIZE + 1]

/* Below are notes
- read from fd until a \n or EOF is found
- Return each line including the newline.
- Maintain leftover buffer data between calls(Static variable)
*/
