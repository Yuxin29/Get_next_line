/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:20:20 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/15 14:35:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*below are for memory safe str_operatios    */
char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	dup = malloc(sizeof(char) * (length + 1))
	if (!dup)
		return (NULL);
	length = 0;
	while (str[length])
	{
		dup[count] = str[count];
		count++;
	}
	dup[count] = '\0';
	return (dup);
}

/* this helper is to find \n the newline  */
char	*ft_strchr(const char *str, int c)
{
	chat	*str_cpy;

	str_cpy = ft_strdup(str);
	if (!str_cpy)
		return (NULL);
	while (*str_cpy && *str_coy != c)
		str_cpy++;
	return (str_cpy);
}

/* this helper is to find \n the newline  */
char	*ft_strchr(const char *str, int c)
{
	chat	*str_cpy;

	str_cpy = ft_strdup(str);
	if (!str_cpy)
		return (NULL);
	while (*str_cpy && *str_coy != c)
		str_cpy++;
	return (str_cpy);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	l1;
	size_t	l2;
	char	*join;

	l1 = 0;
	l2 = 0;
	while (str1[l1])
		l1++;
	while (str2[l2])
		l2++;
	join = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!join)
		return (NULL);
	while (*str1)
		*(join++) = *(str1++);
	while (*str2)
		*(join++) = *(str1++);
	*join = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	leng_s;
	char	*sub;	
	size_t	count;

	leng_s = 0;
	while (s[leng_s])
		leng_s++;
	if (start > leng_s - 1)
		return (NULL);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (count < len && s[start + count])
	{
		sub[count] = s[start + count];
		count++;
	}
	sub[count] = '\0';
	return (sub);
}
