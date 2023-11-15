/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:16:15 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/16 19:09:04 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	check_charset_rev(char const *str, char const *set)
{
	int		i;
	size_t	c;
	int		found;
	int		check;

	i = ft_strlen(str) - 1;
	found = 0;
	check = 1;
	while (check == 1 && i >= 0)
	{
		c = 0;
		check = 0;
		while (c < ft_strlen(set))
		{
			if (str[i] == set[c])
			{
				found += 1;
				check = 1;
				break ;
			}
			c++;
		}
		i--;
	}
	return (found);
}

int	check_charset(char const *str, char const *set)
{
	int		i;
	size_t	c;
	int		found;
	int		check;

	i = 0;
	found = 0;
	check = 1;
	while (check == 1 && str[i] != 0)
	{
		c = 0;
		check = 0;
		while (c < ft_strlen(set))
		{
			if (str[i] == set[c])
			{
				found += 1;
				check = 1;
				break ;
			}
			c++;
		}
		i++;
	}
	return (found);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		rm_s;
	int		rm_e;
	int		len;

	i = 0;
	rm_e = 0;
	len = ft_strlen(s1);
	rm_s = check_charset(s1, set);
	if (rm_s != len)
		rm_e = check_charset_rev(s1, set);
	trim = malloc (len - rm_s - rm_e + 1);
	len = len - rm_s - rm_e;
	if (!trim)
		return (0);
	while (len > 0)
	{
		trim[i] = s1[rm_s];
		i++;
		rm_s++;
		len--;
	}
	trim[i] = 0;
	return (trim);
}
