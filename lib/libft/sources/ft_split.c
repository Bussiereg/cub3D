/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:35 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/05 17:14:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char			**ft_split(char const *s, char c);
static char		*ft_strncpy_mem(char *src, unsigned int n);
static size_t	ft_word_count(char *str, char c);
static size_t	ft_nb_set(char *src, char c);

int	main(void)
{
	char 				str[] =  "  un deux   trois   quatre ";
	//char				str[] = "Tripouille";
	int					i;
	char				c;
	unsigned int		a;
	char 				**tabs;

	i = 0;
	c = ' ';
	a = 0;
	tabs = ft_split(str, c);
	printf("%s%lu%s\n", "la string a decouper a ", strlen(str), " caracteres");	
	printf("%s%lu%s\n", "il y a ", ft_word_count(str, c), " tableaux dans **tab");
	printf("%s%zu%s\n", "fonction ft_nb_set: ", ft_nb_set(str, c), " .");
	while (a < (ft_word_count(str, c)))
	{
		printf("%s\n", tabs[a]);
		free(tabs[a]);
		a++;
	}
	free(tabs);
}
*/

static char	*ft_strncpy_mem(char *src, unsigned int n)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = (char *)malloc(sizeof(*ret) * (n + 1));
	if (!ret)
		return (NULL);
	while (src[i] != '\0' && i < n)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static size_t	ft_word_count(char *str, char c)
{
	int	trigger;
	int	count;

	trigger = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (count);
}

static size_t	ft_nb_set(char *src, char c)
{
	size_t	count_set;

	count_set = 0;
	while (src[count_set] == c)
		count_set++;
	return (count_set);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		h;
	char	*str;
	char	**tabs;

	h = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tabs = ft_calloc(sizeof(*tabs), (ft_word_count(str, c) + 1));
	i = ft_nb_set(str, c);
	j = i;
	while (ft_strlen(s) >= i && ft_word_count(str, c) != 0)
	{
		if (s[i] == c || s[i] == '\0')
		{
			tabs[h++] = ft_strncpy_mem(str + j, i - j);
			j = i + ft_nb_set(str + i, c);
			i = j;
		}
		i++;
	}
	return (tabs);
}
