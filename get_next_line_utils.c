/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:20:20 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/15 10:25:26 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

/* this helper is to find \n the newline  */
static char *ft_strchr(char *str, char)
{
	...
}

/*below are for memory safe str_operatios    */
static char *ft_strdup(char *str)
{
	char	*dup;
	size_t	length;

	length = ft_strlen(str);
	dup = malloc(sizeof(char) * (length + 1))
	if (!dup)
		return (NULL);
	length = 0;
	while (str[length])
	{
		dup[count] = str[count];
		count++:
	}
	dup[count] = '\0';
	return (dup);
}

static char *ft_strjoin(char *str1, char *str2)
{
	size_t	l1;
	size_t	l2;
	char	*join;

	l1 = ft_strlen(str1);
	l2 = ft_strlen(str2);
	join = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!join)
		return (NULL);
	while (*str1)
	{
		*join = *str1;
		join++:
		str1++:
	}
	while (*str2)
	{
		*join = *str2;
		join++;
		str2++
	}
	*join = '\0';
	return (join);
}

void ft_get_next_line_utils(void)
{
	...
}
