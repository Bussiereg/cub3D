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

#include "cub3d_bonus.h"

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

void	delete_img_cub3d(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->background);
	mlx_delete_image(cub3d->mlx, cub3d->viewport);
	mlx_delete_image(cub3d->mlx, cub3d->sprite_img);
	mlx_delete_image(cub3d->mlx, cub3d->minimap);
	mlx_delete_image(cub3d->mlx, cub3d->intro);
	mlx_delete_image(cub3d->mlx, cub3d->key1);
	mlx_delete_image(cub3d->mlx, cub3d->key2);
	mlx_delete_image(cub3d->mlx, cub3d->key3);
	mlx_delete_image(cub3d->mlx, cub3d->key4);
	mlx_delete_image(cub3d->mlx, cub3d->key6);
	mlx_delete_image(cub3d->mlx, cub3d->key7);
	mlx_delete_image(cub3d->mlx, cub3d->text1);
	mlx_delete_image(cub3d->mlx, cub3d->text2);
	mlx_delete_image(cub3d->mlx, cub3d->text3);
	if (cub3d->t_e != cub3d->background)
		mlx_delete_image(cub3d->mlx, cub3d->t_e);
	if (cub3d->t_s != cub3d->background)
		mlx_delete_image(cub3d->mlx, cub3d->t_s);
	if (cub3d->t_n != cub3d->background)
		mlx_delete_image(cub3d->mlx, cub3d->t_n);
	if (cub3d->t_w != cub3d->background)
		mlx_delete_image(cub3d->mlx, cub3d->t_w);
	mlx_terminate(cub3d->mlx);
}

void	terminate(char *str, t_cub3d *cub3d, int mlx, int map)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	if (map == 2)
		ft_free_tab(cub3d->map_check);
	if (map >= 1)
		ft_free_tab(cub3d->map);
	if (mlx == 1)
		delete_img_cub3d(cub3d);
	exit(EXIT_FAILURE);
}
