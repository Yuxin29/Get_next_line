/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:01 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/15 11:37:20 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- access a file
static int	ft_open(const char* path, int flags [, int mode ])
{
	int	re_value;//if return small, non_neg int as fd, -1 on erros

	re_value = open(path, flags);//flags could be: O_RDONLY, O_WTONLY...	
	return (re_value);//0, 1, 2.     and addtional opens: 3, 4
}
[, int mode ] this is optional: only when a new file is created

- read a file 
static ssize_t	ft_read(int fildes, void *buf, size_t nbyte)
{
	ssize_t	r;

	r = ft_read(fildes, buf, nbyte);
	return (r);//+: number of bites read, 0:EOF, -1: erros occured
}
*/

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Error program number");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
        	free(line);
		line = get_next_line(fd);
	}
	//close(fd);
	return (0);
}
