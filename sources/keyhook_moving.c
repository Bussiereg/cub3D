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

#include "cub3d.h"

void	moving_right(t_cub3d *cub3d)
{
	double	mx;
	double	my;

	my = cub3d->pos_y + sin(cub3d->pos_angle + (M_PI / 2)) * OFFSET;
	mx = cub3d->pos_x + cos(cub3d->pos_angle + (M_PI / 2)) * OFFSET;
	if (cub3d->map[(int)my / UNIT][(int)mx / UNIT] == '0')
	{
		cub3d->pos_y = my;
		cub3d->pos_x = mx;
	}
}

void	moving_left(t_cub3d *cub3d)
{
	double	mx;
	double	my;

	my = cub3d->pos_y - sin(cub3d->pos_angle + (M_PI / 2)) * OFFSET;
	mx = cub3d->pos_x - cos(cub3d->pos_angle + (M_PI / 2)) * OFFSET;
	if (cub3d->map[(int)my / UNIT][(int)mx / UNIT] == '0')
	{
		cub3d->pos_y = my;
		cub3d->pos_x = mx;
	}
}

void	moving_down(t_cub3d *cub3d)
{
	if ((cub3d->map[(int)(cub3d->pos_y - (cub3d->pos_dy * OFFSET))
			/ UNIT][(int)(cub3d->pos_x - (cub3d->pos_dx * OFFSET))
			/ UNIT]) == '0')
	{
		cub3d->pos_y -= cub3d->pos_dy * OFFSET;
		cub3d->pos_x -= cub3d->pos_dx * OFFSET;
	}
}

void	moving_up(t_cub3d *cub3d)
{
	if ((cub3d->map[(int)(cub3d->pos_y + (cub3d->pos_dy * OFFSET))
			/ UNIT][(int)(cub3d->pos_x + (cub3d->pos_dx * OFFSET))
			/ UNIT]) == '0')
	{
		cub3d->pos_y += cub3d->pos_dy * OFFSET;
		cub3d->pos_x += cub3d->pos_dx * OFFSET;
	}
}
