/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_moving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:45:27 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/09 12:45:29 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	text_end(t_cub3d *cub3d)
{
	if (cub3d->end == 0)
	{
		cub3d->end = 1;
		cub3d->text2 = mlx_put_string(cub3d->mlx, "THE END",
				WIDTH / 2 - 35, HEIGHT / 2 - 40);
		cub3d->text3 = mlx_put_string(cub3d->mlx, "- press Esc -",
				WIDTH / 2 - 65, HEIGHT / 2 - 20);
	}
}

void	moving_right(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	mlx_delete_image(cub3d->mlx, cub3d->text1);
	my = (cub3d->posy + 2 * (cub3d->plane_y) * STEP);
	mx = (cub3d->posx + 2 * (cub3d->plane_x) * STEP);
	if (cub3d->map[(int)my][(int)mx] == 'Z')
		text_end(cub3d);
	if (cub3d->map[(int)my][(int)mx] == '0'
		|| cub3d->map[(int)my][(int)mx] == 'c'
		|| cub3d->map[(int)my][(int)mx] == 'Z')
	{
		cub3d->posy += cub3d->plane_y * STEP;
		cub3d->posx += cub3d->plane_x * STEP;
		if (cub3d->map[(int)cub3d->posy][(int)cub3d->posx] == 'c')
		{
			cub3d->map[(int)cub3d->posy][(int)cub3d->posx] = '0';
			cub3d->sprite[cub3d->flag2].flag = 0;
			cub3d->key_nb++;
		}
	}
}

void	moving_left(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	mlx_delete_image(cub3d->mlx, cub3d->text1);
	my = (cub3d->posy - 2 * (cub3d->plane_y * STEP));
	mx = (cub3d->posx - 2 * (cub3d->plane_x * STEP));
	if (cub3d->map[(int)my][(int)mx] == 'Z')
		text_end(cub3d);
	if (cub3d->map[(int)my][(int)mx] == '0'
		|| cub3d->map[(int)my][(int)mx] == 'c'
		|| cub3d->map[(int)my][(int)mx] == 'Z')
	{
		cub3d->posy -= cub3d->plane_y * STEP;
		cub3d->posx -= cub3d->plane_x * STEP;
		if (cub3d->map[(int)cub3d->posy][(int)cub3d->posx] == 'c')
		{
			cub3d->map[(int)cub3d->posy][(int)cub3d->posx] = '0';
			cub3d->sprite[cub3d->flag2].flag = 0;
			cub3d->key_nb++;
		}
	}
}

void	moving_down(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	mlx_delete_image(cub3d->mlx, cub3d->text1);
	my = (cub3d->posy - 2 * (cub3d->dir_y * STEP));
	mx = (cub3d->posx - 2 * (cub3d->dir_x * STEP));
	if (cub3d->map[(int)my][(int)mx] == 'Z')
		text_end(cub3d);
	if (cub3d->map[(int)my][(int)mx] == '0'
		|| cub3d->map[(int)my][(int)mx] == 'c'
		|| cub3d->map[(int)my][(int)mx] == 'Z')
	{
		cub3d->posy -= cub3d->dir_y * STEP;
		cub3d->posx -= cub3d->dir_x * STEP ;
		if (cub3d->map[(int)cub3d->posy][(int)cub3d->posx] == 'c')
		{
			cub3d->map[(int)cub3d->posy][(int)cub3d->posx] = '0';
			cub3d->sprite[cub3d->flag2].flag = 0;
			cub3d->key_nb++;
		}
	}
}

void	moving_up(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	mlx_delete_image(cub3d->mlx, cub3d->text1);
	my = (cub3d->posy + 2 * (cub3d->dir_y * STEP));
	mx = (cub3d->posx + 2 * (cub3d->dir_x * STEP));
	if (cub3d->map[(int)my][(int)mx] == 'Z')
		text_end(cub3d);
	if (cub3d->map[(int)my][(int)mx] == '0'
		|| cub3d->map[(int)my][(int)mx] == 'c'
		|| cub3d->map[(int)my][(int)mx] == 'Z')
	{
		cub3d->posy += (cub3d->dir_y * STEP);
		cub3d->posx += (cub3d->dir_x * STEP);
		if (cub3d->map[(int)cub3d->posy][(int)cub3d->posx] == 'c')
		{
			cub3d->map[(int)cub3d->posy][(int)cub3d->posx] = '0';
			cub3d->sprite[cub3d->flag2].flag = 0;
			cub3d->key_nb++;
		}
	}
}
