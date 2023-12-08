/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:20:31 by gbussier          #+#    #+#             */
/*   Updated: 2023/02/27 17:20:33 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*read_till_n;
	char		*line;
	static char	*save[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_till_n = gnl_newline(fd, save[fd]);
	save[fd] = gnl_free(save[fd], NULL);
	if (gnl_strlen(read_till_n) == 0)
		return (gnl_free(read_till_n, NULL));
	if (check_new_line(read_till_n) == -1)
		return (read_till_n);
	line = gnl_strjoin(NULL, read_till_n, check_new_line(read_till_n) + 1);
	if (gnl_strlen(line) == 0)
		return (gnl_free(line, read_till_n));
	save[fd] = gnl_strjoin(NULL, read_till_n + check_new_line(line) + 1,
			gnl_strlen(read_till_n) - gnl_strlen(line) + 1);
	if (gnl_strlen(save[fd]) == 0)
		save[fd] = gnl_free(save[fd], NULL);
	free(read_till_n);
	return (line);
}
