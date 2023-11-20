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

	my = ((cub3d->posY / UNIT) + (cub3d->planeY * MOVESPEED));
	mx = ((cub3d->posX / UNIT) + (cub3d->planeX * MOVESPEED));
	if (cub3d->map[(int)my][(int)mx] == '0')
	{
		cub3d->posY += cub3d->planeY * MOVESPEED;
		cub3d->posX += cub3d->planeX * MOVESPEED;
	}
}

void	moving_left(t_cub3d *cub3d)
{
	double	mx;
	double	my;

	my = ((cub3d->posY / UNIT) - (cub3d->planeY * MOVESPEED));
	mx = ((cub3d->posX / UNIT) - (cub3d->planeX * MOVESPEED));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY -= cub3d->planeY * MOVESPEED;
		cub3d->posX -= cub3d->planeX * MOVESPEED;
	}
}

void	moving_down(t_cub3d *cub3d)
{
	double	mx;
	double	my;

	my = ((cub3d->posY / UNIT) - (cub3d->dirY * MOVESPEED));
	mx = ((cub3d->posX / UNIT) - (cub3d->dirX * MOVESPEED));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY -= cub3d->dirY * MOVESPEED;
		cub3d->posX -= cub3d->dirX * MOVESPEED;
	}
}

void	moving_up(t_cub3d *cub3d)
{
	double	mx;
	double	my;

	my = ((cub3d->posY / UNIT) + (cub3d->dirY * MOVESPEED));
	mx = ((cub3d->posX / UNIT) + (cub3d->dirX * MOVESPEED));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY += cub3d->dirY * MOVESPEED;
		cub3d->posX += cub3d->dirX * MOVESPEED;
	}
}
