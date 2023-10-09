/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:00:05 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/07 11:21:32 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);


int	main(void)
{
	char dest[] = "abcdefghijklmnopq";
	const char src[] = "123456789";
	size_t size;
	size_t a;
	int i;

	i = 0;
	a = strlen(dest);
	size = 1;
	printf("%s%ld\n", "ft_strlcpy return: ", ft_strlcpy(dest, src, size));
	printf("la chaine de caractere apres copie mais sans le NUL est: ");
	while(a--)
		printf("%c", *(dest + i++)); 
	printf("\n");
	printf("%s%s", "destination is: ", dest);
}
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size == 0)
		return (ft_strlen(src));
	while ((*(src + len) && --size))
	{
		*(dst + len) = *(src + len);
		len++;
	}
	*(dst + len) = '\0';
	while (*(src + len))
		len++;
	return (len);
}
