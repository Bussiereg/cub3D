/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:44:14 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/06 14:12:22 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
#include <string.h>
#include <stdio.h>

void *ft_memset(void *s, int c, size_t n);

int	main(void)
{
	char str[] = "hELLO wORLD";
	int	c;
	size_t n;

	c = 'a';
	n = 5;

	puts (memset(str, c, n));
	puts (ft_memset(str, c, n));
}
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
