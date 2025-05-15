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

//extracts the next line (up to the '\n' from the full line buffer)
//line_buffer: a string of contents read so far
// return: a new string cccontaining the line to return;
char	*ft_get_line(char	*line_buffer)
{
	//where do we get the line_buffer???
}

//read and fills the line buffer
//left_c: the remaining unread data
char	*ft_fill_line_buffer(int fd, char *left_c, char *buffer)
{
		return (?);
}

char	*ft_get_next_line(int fd)
{
	static char	*remainder;

}


/* Below are notes

- read from fd until a \n or EOF is found
- Return each line including the newline.
- Maintain leftover buffer data between calls(Static variable)

*/
