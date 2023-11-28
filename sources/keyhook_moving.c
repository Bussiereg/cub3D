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
	float	mx;
	float	my;

	my = (cub3d->posy + (cub3d->plane_y) * STEP);
	mx = (cub3d->posx + (cub3d->plane_x) * STEP);
	if (cub3d->map[(int)my][(int)mx] == '0')
	{
		cub3d->posy += cub3d->plane_y * STEP;
		cub3d->posx += cub3d->plane_x * STEP;
	}
}

void	moving_left(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	my = (cub3d->posy - (cub3d->plane_y * STEP));
	mx = (cub3d->posx - (cub3d->plane_x * STEP));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posy -= cub3d->plane_y * STEP;
		cub3d->posx -= cub3d->plane_x * STEP;
	}
}

void	moving_down(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	my = (cub3d->posy - (cub3d->dir_y * STEP));
	mx = (cub3d->posx - (cub3d->dir_x * STEP));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posy -= cub3d->dir_y * STEP;
		cub3d->posx -= cub3d->dir_x * STEP ;
	}
}

void	moving_up(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	my = (cub3d->posy + (cub3d->dir_y * STEP));
	mx = (cub3d->posx + (cub3d->dir_x * STEP));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posy += (cub3d->dir_y * STEP);
		cub3d->posx += (cub3d->dir_x * STEP);
	}
}
