/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:45:39 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/05 10:48:52 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int	main (void)
{
	char dest[] = "000000000000000000000000000000";
	const char src[] = "123";
	size_t size;

	size = 0;
	printf("%s%zu\n", "ft_strlcat return: ", ft_strlcat(dest, src, size));
	printf("%s%s", "destination is: ", dest);
}
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dst && i < size)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, size - i);
	return (ret + i);
}
