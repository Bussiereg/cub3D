/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:08:52 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 17:09:07 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst);

int main(void)
{
	t_list	*result;
	t_list	*lst;
	t_list	*first = NULL;
	t_list	*second = NULL;
	int		un;
	int		deux;
	
	un = 1;
	deux = 2;

	first = (t_list *)malloc(sizeof(*first));
	second = (t_list *)malloc(sizeof(*second));
	
	first->content = &un;
	second->content = &deux;
	first->next = second;
	second->next = NULL;
	lst = first;

	result = ft_lstlast(lst);
	printf("%p", result->content);
}
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
