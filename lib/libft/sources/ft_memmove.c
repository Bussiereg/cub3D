/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:14:33 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/14 17:28:54 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n);

int	main(void)
{
	char str[] = "memmove can be very useful......";
	size_t n;

	n = 11;

	//memmove(str + 15, str + 20, n);
	//puts(str);
	ft_memmove(str + 15, str + 20, n);
	puts(str);
}
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;
	size_t				i;

	i = n;
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (ptrsrc < ptrdest)
	{
		while (i > 0)
		{
			ptrdest[i - 1] = ptrsrc[i - 1];
			i--;
		}
	}
	i = 0;
	if (ptrsrc > ptrdest)
	{
		while (n > i)
		{
			ptrdest[i] = ptrsrc[i];
			i++;
		}
	}
	return (dest);
}
