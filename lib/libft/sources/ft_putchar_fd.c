/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:36:28 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 19:20:40 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
/*
void	ft_putchar_fd(char c, int  fd);

int	main(void)
{
	char c;
	int fd;

	c = 'a';
	fd = 1;
	ft_putchar_fd(c, fd);
}
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
