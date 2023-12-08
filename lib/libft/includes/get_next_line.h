/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:19:23 by gbussier          #+#    #+#             */
/*   Updated: 2023/02/28 13:39:02 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char			*get_next_line(int fd);
unsigned int	gnl_strlen(const char *str);
int				check_new_line(char	*str);
char			*gnl_newline(int fd, char *save);
char			*gnl_strjoin(char const *s1, char const *s2,
					unsigned int size_add);
char			*gnl_read(char *read_save, char *result, int fd);
void			*gnl_free(char *str1, char *str2);

#endif
