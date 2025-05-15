/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:24:16 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/15 13:21:16 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>		//malloc and free
#include <fcntl.h>		//header for file control systems: open and read
#include <stdarg.h>		//for variable arguments

//major functions
char    *ft_get_next_line(int fd);

//helper functions
size_t   ft_strlen(char *str);
char    *ft_strchr(const char *str, int c);
char    *ft_strdup(char *str);
char    *ft_strchr(const char *str, int c);
char    *ft_strjoin(char *str1, char *str2);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif
