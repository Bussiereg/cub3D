/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:02:34 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/08 16:09:17 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main(void)
{
	//char str[] = "bonjour";
	int tab[7] = {49, -49, 300, 1, 0, 2, 2};
	int	c;
	size_t	n;

	c = -49;
	n = 2;
	printf("%p\n", memchr(tab, c, n));
	printf("%p\n", ft_memchr(tab, c, n));
}
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (n > i)
	{
		if (*(str + i) == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
