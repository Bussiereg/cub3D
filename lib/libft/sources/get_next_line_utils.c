/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:20:09 by gbussier          #+#    #+#             */
/*   Updated: 2023/02/27 17:20:11 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	gnl_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_read(char *read_save, char *result, int fd)
{
	int	count;

	count = 0;
	while (check_new_line(read_save) == -1)
	{
		count = read(fd, read_save, BUFFER_SIZE);
		if (count == 0)
		{
			free(read_save);
			return (result);
		}
		if (count == -1)
			return (gnl_free(read_save, result));
		read_save[count] = '\0';
		result = gnl_strjoin(result, read_save, gnl_strlen(read_save));
		if (gnl_strlen(result) == 0)
			result = gnl_free(result, NULL);
	}
	free(read_save);
	return (result);
}

char	*gnl_newline(int fd, char *save)
{
	char	*read_save;
	char	*result;

	result = NULL;
	read_save = (char *) malloc (sizeof(read_save) * (BUFFER_SIZE + 1));
	if (!read_save)
		return (NULL);
	read_save[0] = '\0';
	if (save)
	{
		result = gnl_strjoin(result, save, gnl_strlen(save));
		if (gnl_strlen(result) == 0)
			result = gnl_free(result, NULL);
		if (check_new_line(result) >= 0)
		{
			free(read_save);
			return (result);
		}
	}
	return (gnl_read(read_save, result, fd));
}

int	check_new_line(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char const *s1, char const *s2, unsigned int size_add)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(*str) * (gnl_strlen(s1) + size_add + 1));
	if (!str)
		return (gnl_free((void *)s1, NULL));
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && size_add--)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free((void *)s1);
	return (str);
}
