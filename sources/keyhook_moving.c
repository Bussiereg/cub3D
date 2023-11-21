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

	my = ((cub3d->posY / UNIT) + (cub3d->planeY) / 2);
	mx = ((cub3d->posX / UNIT) + (cub3d->planeX) / 2);
	if (cub3d->map[(int)my][(int)mx] == '0')
	{
		cub3d->posY += cub3d->planeY / 2;
		cub3d->posX += cub3d->planeX / 2;
	}
}

void	moving_left(t_cub3d *cub3d)
{
	double	mx;
	double	my;

	my = ((cub3d->posY / UNIT) - (cub3d->planeY / 2));
	mx = ((cub3d->posX / UNIT) - (cub3d->planeX / 2));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY -= cub3d->planeY / 2;
		cub3d->posX -= cub3d->planeX / 2;
	}
}

void	moving_down(t_cub3d *cub3d)
{
	double	mx;
	double	my;

	my = ((cub3d->posY / UNIT) - (cub3d->dirY / 2));
	mx = ((cub3d->posX / UNIT) - (cub3d->dirX / 2));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY -= cub3d->dirY / 2;
		cub3d->posX -= cub3d->dirX / 2 ;
	}
}

void	moving_up(t_cub3d *cub3d)
{
	double	mx;
	double	my;

	my = ((cub3d->posY / UNIT) + (cub3d->dirY / 2));
	mx = ((cub3d->posX / UNIT) + (cub3d->dirX / 2));
	if ((cub3d->map[(int)my][(int)mx]) == '0')
	{
		cub3d->posY += (cub3d->dirY / 2);
		cub3d->posX += (cub3d->dirX / 2);
	}
}
