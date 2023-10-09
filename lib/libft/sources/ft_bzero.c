/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:12:27 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/06 14:05:17 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
#include <strings.h>
#include <stdio.h>

void ft_bzero(void *s, size_t n);

int	main(void)
{
	size_t	n;
	char	str1[] = "Hello World";
	char	str2[] = "Hello World";


	n = 3;
	bzero(str1, n);
	puts(str1 + n - 1);
	ft_bzero(str2, n);
	puts(str2 + n - 1);
}
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
