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

void	raycaster(t_cub3d *cub3d, double ra)
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
		if (ra < M_PI)
		{
			pixel = tx / UNIT * cub3d->t_s->height;
			draw_line_textu(line_height, cub3d->t_s->height - pixel - 1,
				cub3d->t_s, cub3d);
		}
		else
		{
			pixel = tx / UNIT * cub3d->t_n->height;
			draw_line_textu(line_height, pixel, cub3d->t_n, cub3d);
		}
	}
	else
	{
		tile_d = (int)cub3d->wall_y / UNIT;
		tx = cub3d->wall_y - tile_d * UNIT;
		if (ra <= M_PI_2 || ra >= (3 * M_PI_2))
		{
			pixel = tx / UNIT * cub3d->t_e->height;
			draw_line_textu(line_height, pixel, cub3d->t_e, cub3d);
		}
		else
		{
			pixel = tx / UNIT * cub3d->t_w->height;
			draw_line_textu(line_height, cub3d->t_w->height - pixel - 1,
				cub3d->t_w, cub3d);
		}
	}
}
