/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:07:55 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 17:07:57 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


void	ft_lstadd_front(t_list **lst, t_list *new);

int	main(void)
{
	t_list	**lst;
	t_list	*first = NULL;
	t_list	*second = NULL;
	t_list	*new = NULL;
	int		un;
	int		deux;
	char	c;
	
	un = 1;
	deux = 2;
	c = 'c';

	first = (t_list *)malloc(sizeof(*first));
	second = (t_list *)malloc(sizeof(*second));
	new = (t_list *)malloc(sizeof(*new));
	
	first->content = &un;
	second->content = &deux;
	first->next = second;
	second->next = NULL;
	lst = &first;
	new->content = &c;
	new->next = NULL;
	ft_lstadd_front(lst, new);
	printf("%p", (*lst)->content);	
}
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
