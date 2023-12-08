/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:10:02 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 17:10:03 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
void	ft_lstdelone(t_list *lst, void (*del)(void *));

int main(void)
{
	t_list	*lst;
	t_list	first;
	t_list	second;
	int		un;
	int		deux;
	
	un = 1;
	deux = 2;

	first = (t_list)malloc(sizeof(first));
	second = (t_list)malloc(sizeof(second));
	
	first->content = &un;
	second->content = &deux;
	first->next = second;
	second->next = NULL;
	lst = &first;

	ft_lstdelone(lst, del();
	printf("%p", result->content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
