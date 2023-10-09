/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:08:15 by gbussier          #+#    #+#             */
/*   Updated: 2022/12/19 17:08:22 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	ft_lstsize(t_list *lst);

int	main(void)
{
}
*/

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst->next = lst->next->next;
		size++;
	}
	return (size);
}
