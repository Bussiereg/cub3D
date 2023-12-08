/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:51:50 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/06 14:07:50 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c);

int	main(void)
{	
	int	c;

	c = '5';
	printf("%d\n",ft_isalnum(c));
//	printf("%d\n",isalnum(c));
}
*/
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	return (0);
}
