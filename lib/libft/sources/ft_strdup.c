/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:59:40 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/06 15:03:32 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	src[] = "Hello";

	printf ("%s\n", ft_strdup(src));
	printf ("%s\n", strdup(src));
}
*/

char	*ft_strdup(char	*src)
{
	char	*tab;
	int		i;

	tab = NULL;
	i = 0;
	if (src)
	{
		tab = (char *)malloc(sizeof (*tab) * (ft_strlen(src) + 1));
		if (!tab)
			return (NULL);
		while (src[i] != '\0')
		{
			tab[i] = src[i];
			i++;
		}
		tab[i] = '\0';
	}
	return (tab);
}
