/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:10:42 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/16 13:12:57 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	result;

	signe = 1;
	result = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * signe);
}
/*
int	main(int argc, char *argv[])
{
	int	b;
	int	c;

	if (argc != 2)
		printf ("%s\n", "Sorry, Wrong number of arguments");
	if (argc == 2)
	{
		b = ft_atoi(argv[1]);
		printf ("%d\n", b);
		c = atoi(argv[1]);
		printf ("%d\n", c);
	}
	return (0);
}*/
