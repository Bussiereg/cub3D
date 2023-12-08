/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:16:02 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/16 13:43:45 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>

int	main(void)
{
	size_t	nmemb;
	size_t	size;
	void	*ptr;

	nmemb = 0;
	size = 0;
	ptr = ft_calloc(nmemb, size);
	printf("%p\n", ptr);
//	printf("%p\n", calloc(nmemb, size));
	free (ptr);
}
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
