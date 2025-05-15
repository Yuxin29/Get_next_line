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

#include "get_next_line.h"

/* access a file */
/* [, int mode ] this is optional: only when a new file is created */
static int	ft_open (const char* path, int flags [, int mode ])
{
	int re_value;//if return small, non_neg int as fd, -1 on erros

	re_value = open(path, flags);//flags could be: O_RDONLY, O_WTONLY...	
	return (re_value);//0, 1, 2.     and addtional opens: 3, 4
}

/* read a file */
//ssize_t: signed version of size_t, represents both nbrs and errors
static ssize_t	ft_read(int fildes, void *buf, size_t nbyte)
{
	ssize_t	r;

	return (r);   //+: number of bites read, 0:EOF, -1: erros occured
}

int	main(void)
{
	int	fd;

	fd = ft_open("gnl_test"; 0_RDONLY);	
	if (fd == -1)
	{
		write(1, "error", 5)
		return (0);
	}
	//opening successful, can go to next step
	ft_read;
	return (0);
}
