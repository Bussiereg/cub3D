/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:59:20 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 15:47:39 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
/*
void	ft_putnbr_fd(int nb, int fd);

int	main(void)
{
	int	fd;
	int	nb;

	nb = -100000;
	fd = 1;
	ft_putnbr_fd(nb, fd);
	return (0);
}
*/

void	ft_putnbr_fd(int nb, int fd)
{
	char	x;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb >= 0 && nb <= 9)
	{
		x = nb + '0';
		write(fd, &x, 1);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
