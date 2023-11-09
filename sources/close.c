/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:32 by jubernar          #+#    #+#             */
/*   Updated: 2023/01/06 15:55:35 by jubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	terminate(char *str, t_cub3d *cub3d, int mlx)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	if (mlx == 1)
	{
		mlx_delete_image(cub3d->mlx, cub3d->viewport);
		mlx_terminate(cub3d->mlx);
	}
	exit(EXIT_FAILURE);
}
