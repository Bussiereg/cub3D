/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:59:20 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/11 15:53:04 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_put_char(char c);
/*
int	ft_put_u(unsigned int nb);

int	main(void)
{
	int	nb;
	int a;

	nb = 100000;
	a = ft_put_u(nb);
	printf("\n%d", a);
	return (0);
}
*/

int	ft_put_u(unsigned int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb <= 9)
	{
		x = nb + '0';
		count = count + ft_put_char(x);
	}
	else if (nb > 9)
	{
		count = count + ft_put_u(nb / 10);
		count = count + ft_put_u(nb % 10);
	}
	return (count);
}
