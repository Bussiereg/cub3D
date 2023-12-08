/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:36:28 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/11 15:09:50 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
int	ft_put_char(char c);

int	main(void)
{
	char c;
	int fd;

	c = 'a';
	fd = 1;
	ft_putchar_fd(c, fd);
}
*/

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}
