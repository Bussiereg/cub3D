/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:51:45 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/06 14:06:38 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
#include <stdio.h>

size_t	ft_strlen(const char *str);

int	main(void)
{
	char	chaine[]  = "Salut";
	ft_strlen(chaine);
	printf("%d", ft_strlen(chaine));
}
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}
