/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:13:27 by seunan            #+#    #+#             */
/*   Updated: 2023/08/17 17:05:05 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1048575
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*repeat_read(char **backup, int fd, char *buf, int size);
char	*ret_line(char **backup);
char	*update_line(char **backup, char *line, char *cut);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);

#endif
