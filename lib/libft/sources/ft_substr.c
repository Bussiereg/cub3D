/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:14:26 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/05 11:41:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const	*s, unsigned int start, size_t len);

int	main(void)
{
	unsigned int	start;
	char const		str[] = "lorem ipsum dolor sit amet";
	size_t			len;
	char 			*result;

	start = 45;
	len = 7;
	result = ft_substr(str, start, len);
	printf("%s", result);
	free (result);
}
*/

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	char	*substr;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *)malloc(sizeof(*substr) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
