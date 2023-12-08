/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:46:53 by gbussier          #+#    #+#             */
/*   Updated: 2022/11/28 14:49:11 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c);

int	main(void)
{	
	char	c;

	c = '0';
	printf("%d\n",ft_isdigit(c));
	printf("%d\n",isdigit(c));
}
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
