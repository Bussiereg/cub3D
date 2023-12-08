/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:41:49 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/11 15:15:13 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_put_char(char c);
int	ft_put_nbr(int nb);
int	ft_put_str(char *str);
/*
int	main(void)
{
	int	nb;
	int	a;

	nb = -2147483648;
	a = ft_put_nbr(nb);
	printf("\n%d", a);
	return (0);
}
*/

int	ft_put_nbr(int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb == -2147483648)
		count = ft_put_str("-2147483648");
	else if (nb < 0)
	{
		count = ft_put_char('-');
		count = count + ft_put_nbr(-nb);
	}
	else if (nb >= 0 && nb <= 9)
	{
		x = nb + '0';
		count = ft_put_char(x);
	}
	else if (nb > 9)
	{
		count = count + ft_put_nbr(nb / 10);
		count = count + ft_put_nbr(nb % 10);
	}
	return (count);
}
