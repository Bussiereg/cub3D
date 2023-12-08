/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:46:08 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/16 11:36:31 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_put_xlong(unsigned long nb, char *base);
int	ft_put_str(char *s);
int	ft_put_ptr(void *ptr, char *base);
int	ft_put_char(char c);

/* int main(void)
{
	int	a = 5;
	int b;
	int c;

    b = ft_put_ptr(&a);
	c = printf("\n%p", &a);
	printf("\n%d\n%d", b, c);
} */

int	ft_put_xlong(unsigned long nb, char *base)
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
		count = count + ft_put_xlong(nb / 16, base);
		count = count + ft_put_xlong(nb % 16, base);
	}
	return (count);
}

int	ft_put_ptr(void *ptr, char *base)
{
	int				count;
	unsigned long	result;

	result = (unsigned long)ptr;
	if ((void *)result == NULL)
		return (ft_put_str("(nil)"));
	count = ft_put_str("0x") + ft_put_xlong(result, base);
	return (count);
}
