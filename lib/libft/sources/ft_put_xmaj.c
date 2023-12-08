/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:37:23 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/16 10:44:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_put_xmaj(unsigned int nb, char *base);
int	ft_put_char(char c);
/*
int main(void)
{
	int	a;

	a = ft_put_x(549651354, "0123456789ABCDEF");
	printf("\n%d", a);
}
*/

int	ft_put_xmaj(unsigned int nb, char *base)
{
	char	x;
	int		count;

	count = 0;
	if (nb < 16)
	{
		x = base[nb];
		count = ft_put_char(x);
	}
	else if (nb >= 16)
	{
		count = count + ft_put_xmaj(nb / 16, base);
		count = count + ft_put_xmaj(nb % 16, base);
	}
	return (count);
}
