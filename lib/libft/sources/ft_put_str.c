/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:48:46 by gbussier          #+#    #+#             */
/*   Updated: 2023/01/13 13:55:49 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

int	ft_put_str(char *s);
/*
int	main(void)
{
	char	chaine[] = "";
	
	printf("%s", chaine);
	//ft_put_str(chaine);
	//printf("%d", ft_put_str(chaine));
}
*/

int	ft_put_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_put_str("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
