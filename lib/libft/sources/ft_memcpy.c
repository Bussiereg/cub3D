/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:49:15 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 17:45:13 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
#include <string.h>
#include <stdio.h>

void *ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char dest[] = "\0";
	char src[] = "\0";
	size_t n;

	n = 0;

	puts (memcpy(dest, src, n));
	puts (ft_memcpy(dest, src, n));
}
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;
	size_t				i;

	i = 0;
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}
