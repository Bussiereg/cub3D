/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:17:19 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:17:23 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycaster(t_cub3d *cub3d, double ra, int ray)
{
	double	ca;
	double	tx;
	int		tile_d;
	int		pixel;
	double	line_height;

	ca = fix_angle(cub3d->pos_angle - ra);
	cub3d->final_d = cub3d->final_d * cos(ca);
	line_height = (HEIGHT * ((double)WIDTH / (double)HEIGHT)) / (cub3d->final_d
			/ UNIT);
	if (cub3d->disth < cub3d->distv)
	{
		tile_d = (int)cub3d->wall_x / UNIT;
		tx = cub3d->wall_x - tile_d * UNIT;
		pixel = tx / UNIT * cub3d->S->height;
		if (ra < M_PI)
			draw_line_textu(line_height, ray, cub3d->S->height - pixel - 1,
				cub3d->S, cub3d);
		else
		{
			pixel = tx / UNIT * cub3d->N->height;
			draw_line_textu(line_height, ray, pixel, cub3d->N, cub3d);
		}
	}
	else
	{
		tile_d = (int)cub3d->wall_y / UNIT;
		tx = cub3d->wall_y - tile_d * UNIT;
		pixel = tx / UNIT * cub3d->S->height;
		if (ra <= M_PI_2 || ra >= (3 * M_PI_2))
			draw_line_textu(line_height, ray, pixel, cub3d->E, cub3d);
		else
			draw_line_textu(line_height, ray, cub3d->E->height - pixel - 1,
				cub3d->W, cub3d);
	}
}
