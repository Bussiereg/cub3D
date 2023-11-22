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

	my = (cub3d->posY + (cub3d->planeY) * STEP);
	mx = (cub3d->posX + (cub3d->planeX) * STEP);
	if (cub3d->map[(int)my][(int)mx] == '0')
	{
		cub3d->posY += cub3d->planeY * STEP;
		cub3d->posX += cub3d->planeX * STEP;
	}
}

void	moving_left(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	my = (cub3d->posY - (cub3d->planeY * STEP));
	mx = (cub3d->posX - (cub3d->planeX * STEP));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY -= cub3d->planeY * STEP;
		cub3d->posX -= cub3d->planeX * STEP;
	}
}

void	moving_down(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	my = (cub3d->posY - (cub3d->dirY * STEP));
	mx = (cub3d->posX - (cub3d->dirX * STEP));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY -= cub3d->dirY * STEP;
		cub3d->posX -= cub3d->dirX * STEP ;
	}
}

void	moving_up(t_cub3d *cub3d)
{
	float	mx;
	float	my;

	my = (cub3d->posY + (cub3d->dirY * STEP));
	mx = (cub3d->posX + (cub3d->dirX * STEP));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY += (cub3d->dirY * STEP);
		cub3d->posX += (cub3d->dirX * STEP);
	}
}
