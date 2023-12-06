/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:51 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	win_close(void *param)
{
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->viewport);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->sprite_img);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->intro);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->background);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->minimap);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->t_n);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->t_e);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->t_s);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->t_w);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->key1);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->key2);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->key3);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->key4);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->key5);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->key6);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->key7);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->text1);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->text2);
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->text3);
	mlx_terminate(((t_cub3d *)param)->mlx);
	kill(((t_cub3d *)param)->music_pid, SIGUSR1);
	exit(EXIT_SUCCESS);
}

void	my_keyhook_move(mlx_key_data_t keydata, t_cub3d	*cub3d)
{
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_PRESS)
		cub3d->move_up = 1;
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_RELEASE)
		cub3d->move_up = 0;
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_PRESS)
		cub3d->move_down = 1;
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_RELEASE)
		cub3d->move_down = 0;
	if ((keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_PRESS)
		cub3d->move_left = 1;
	if ((keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_RELEASE)
		cub3d->move_left = 0;
	if ((keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_PRESS)
		cub3d->move_right = 1;
	if ((keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_RELEASE)
		cub3d->move_right = 0;
}

void	my_keyhook_rotate(mlx_key_data_t keydata, t_cub3d *cub3d)
{
	if ((keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		cub3d->rotate_left = 1;
	if ((keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
		cub3d->rotate_left = 0;
	if ((keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		cub3d->rotate_right = 1;
	if ((keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
		cub3d->rotate_right = 0;
}

void	my_keyhook_other(mlx_key_data_t keydata, t_cub3d *cub3d)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		kill(cub3d->music_pid, SIGUSR1);
		win_close(cub3d);
	}
	if ((keydata.key == MLX_KEY_M)
		&& keydata.action == MLX_PRESS)
		cub3d->minimap_on ++;
	if ((keydata.key == MLX_KEY_SPACE)
		&& keydata.action == MLX_PRESS && cub3d->key_nb == 3)
		cub3d->door_open = 1;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	my_keyhook_move(keydata, cub3d);
	my_keyhook_rotate(keydata, cub3d);
	my_keyhook_other(keydata, cub3d);
}
