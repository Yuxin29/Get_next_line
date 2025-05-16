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

size_t	ft_strlen(char *str)
{
	size_t	count;
	
	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	length;

	length = 0;
	length = ft_strlen(str);
	dup = malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	length = 0;
	while (str[length])
	{
		dup[length] = str[length];
		length++;
	}
	dup[length] = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (char *)(str);
		str++;
	}
	if (c == '\0')
		return (char *)(str);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	l1;
	size_t	l2;
	char	*join;
	size_t	i;

	if (!str1)
		l1 = 0;
	else
		l1 = ft_strlen(str1);
	if (!str2)
		l2 = 0;
	else
		l2 = ft_strlen(str2);
	join = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!join)
		return (NULL);
	i = 0;
	if (str1)
	{
		while (str1[i])
		{
			join[i] = str1[i];
			i++;
		}
	}
	i = 0;
	if (str2)
	{
		while (str2[i])
		{
			join[l1 + i] = str2[i];
			i++;
		}
	}
	join[l1 + l2] = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	n;
	size_t	max;

	if (!s)
		return (NULL);
	max = ft_strlen((char *)s);
	if (start >= max)
		return (ft_strdup(""));
	if (start + len <= max)
		sub = malloc(sizeof(char) * (len + 1));
	else
		sub = malloc(sizeof(char) * (max - start + 1));
	if (!(sub))
		return (NULL);
	n = 0;
	while (s[start + n] && n < len)
	{
		sub[n] = s[start + n];
		n++;
	}
	sub[n] = '\0';
	return (sub);
}
