/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:49:51 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 18:52:09 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>
#include <string.h>

char				*ft_itoa(int n);
static unsigned int	ft_sizint(int nb);
static char	*ft_convert(int n, int len, char *str);

int	main(void)
{
	int	n;
	char	*str;

	n = 0;
	str = ft_itoa(n);

	printf("%s\n", str);
	printf("%s\n", ft_itoa(465));
	printf("%s\n", ft_itoa(13));
	printf("%s\n", ft_itoa(-1));
	printf("%s\n", ft_itoa(-2));
	printf("%s\n", ft_itoa(-2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-56));
	free (str);
}
*/

static unsigned int	ft_sizint(int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == -2147483648)
		return (11);
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = nb * (-1);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_convert(int n, int len, char *str)
{
	while (n != 0)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;

	len = ft_sizint(n);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
	{
		str[len - 1] = ((n % 10) * (-1)) + 48;
		n = n / 10;
		len--;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
		str = ft_convert(n, len, str);
	}
	else
		str = ft_convert(n, len, str);
	return (str);
}
