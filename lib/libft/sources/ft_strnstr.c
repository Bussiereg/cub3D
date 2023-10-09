/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:00:55 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/05 09:37:22 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t		i;
	char		*str;
	size_t		taille;

	str = (char *)big;
	taille = ft_strlen(little);
	if (ft_strlen(little) > len)
		return (NULL);
	if (((ft_strlen(big) < ft_strlen(little)) && len < ft_strlen(little))
		|| (len == 0 && ft_strlen(little) > 0))
		return (NULL);
	if (ft_strncmp(str, (char *)little, len) == 0 || ft_strlen(little) == 0)
		return (str);
	i = 0;
	while (str[i] && i + taille <= len)
	{
		if (ft_strncmp((str + i), little, taille) == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
