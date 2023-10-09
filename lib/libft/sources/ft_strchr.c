/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:52:10 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/05 08:45:16 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c);

int	main(void)
{
	char str[] = "Hellt";
	int c;

	c = 't' + 256;
	printf ("%s\n", strchr(str, c));
	printf ("%s\n", ft_strchr(str, c));
}
*/

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (c % 256))
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
