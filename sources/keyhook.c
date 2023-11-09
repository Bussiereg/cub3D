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

#include "cub3d.h"

void	win_close(void *param)
{
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->viewport);
	mlx_terminate(((t_cub3d *)param)->mlx);
	exit(EXIT_SUCCESS);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;
	double	mx;
	double	my;

	cub3d = (t_cub3d *)param;
	// going up
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		if ((cub3d->map[(int)(cub3d->pos_y + (cub3d->pos_dy * OFFSET))
				/ UNIT][(int)(cub3d->pos_x + (cub3d->pos_dx * OFFSET))
				/ UNIT]) == '0')
		{
			cub3d->pos_y += cub3d->pos_dy * OFFSET;
			cub3d->pos_x += cub3d->pos_dx * OFFSET;
		}
	}
	// going down
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		if ((cub3d->map[(int)(cub3d->pos_y - (cub3d->pos_dy * OFFSET))
				/ UNIT][(int)(cub3d->pos_x - (cub3d->pos_dx * OFFSET))
				/ UNIT]) == '0')
		{
			cub3d->pos_y -= cub3d->pos_dy * OFFSET;
			cub3d->pos_x -= cub3d->pos_dx * OFFSET;
		}
	}
	// moving left
	else if ((keydata.key == MLX_KEY_A) && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		my = cub3d->pos_y - sin(cub3d->pos_angle + (M_PI / 2)) * OFFSET;
		mx = cub3d->pos_x - cos(cub3d->pos_angle + (M_PI / 2)) * OFFSET;
		if (cub3d->map[(int)my / UNIT][(int)mx / UNIT] == '0')
		{
			cub3d->pos_y = my;
			cub3d->pos_x = mx;
		}
	}
	// moving right
	else if ((keydata.key == MLX_KEY_D) && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		my = cub3d->pos_y + sin(cub3d->pos_angle + (M_PI / 2)) * OFFSET;
		mx = cub3d->pos_x + cos(cub3d->pos_angle + (M_PI / 2)) * OFFSET;
		if (cub3d->map[(int)my / UNIT][(int)mx / UNIT] == '0')
		{
			cub3d->pos_y = my;
			cub3d->pos_x = mx;
		}
	}
	// rotating left
	else if ((keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		cub3d->pos_angle -= ROTATE;
		cub3d->pos_angle = fix_angle(cub3d->pos_angle);
		cub3d->pos_dx = cos(cub3d->pos_angle);
		cub3d->pos_dy = sin(cub3d->pos_angle);
	}
	// rotating right
	else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == 68)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		cub3d->pos_angle += ROTATE;
		cub3d->pos_angle = fix_angle(cub3d->pos_angle);
		cub3d->pos_dx = cos(cub3d->pos_angle);
		cub3d->pos_dy = sin(cub3d->pos_angle);
	}
	// render(&cub3d);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		win_close(param);
}
