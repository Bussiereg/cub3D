/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascci.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:03:32 by gbussier          #+#    #+#             */
/*   Updated: 2022/11/28 15:21:21 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c);

int	main(void)
{	
	int	c;

	c = 'a';
	printf("%d\n",ft_isascii(c));
	printf("%d\n",isascii(c));
}
*/
int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	return (0);
}
