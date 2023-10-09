/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:25:47 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/06 14:50:21 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
*/
//int	ft_isprint(int c);
/*
int	main(void)
{	
	int	c;

	c = 'a';
	printf("%d\n",ft_isprint(c));
	printf("%d\n",isprint(c));
}
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	return (0);
}
