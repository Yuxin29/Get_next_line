/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:34:35 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/20 20:35:57 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
//# include <limits.h>

#define BUFFER_SIZE 5

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
