/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:07:39 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 19:02:51 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>

t_list	*ft_lstnew(void *content);

int	main(void)
{
	void	*test;
	int		i;

	i = 1;
	test = &i;
	printf("%p", ft_lstnew(test));
}
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(*head));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
