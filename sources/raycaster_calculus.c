/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_calculus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:23:41 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:23:42 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	fix_angle(double a)
{
	if (a > (2 * M_PI))
		a -= (2 * M_PI);
	else if (a <= 0)
		a += (2 * M_PI);
	return (a);
}

void	check_horizontal_line(t_cub3d *cub3d, double ra, int lim)
{
	cub3d->disth = 100000000;
	if (ra > M_PI)
	{
		cub3d->hy = ((int)cub3d->posY / UNIT) * UNIT - 0.0001;
		cub3d->hx = ((cub3d->posY - cub3d->hy) * (-1 / tan(ra)))
			+ cub3d->posX;
		cub3d->yo = -UNIT;
		cub3d->xo = -cub3d->yo * (-1 / tan(ra));
	}
	else if (ra < M_PI)
	{
		cub3d->hy = ((int)cub3d->posY / UNIT) * UNIT + UNIT;
		cub3d->hx = ((cub3d->posY - cub3d->hy)) * (-1 / tan(ra))
			+ cub3d->posX;
		cub3d->yo = UNIT;
		cub3d->xo = -cub3d->yo * (-1 / tan(ra));
	}
	else if (ra == 0 || ra == M_PI)
	{
		cub3d->hx = cub3d->posX;
		cub3d->hy = cub3d->posY;
		lim = cub3d->m_size_y;
	}
	dist_to_horizontal_wall(cub3d, cub3d->xo, cub3d->yo, lim);
}

void	check_vertical_line(t_cub3d *cub3d, double ra, int lim)
{
	cub3d->distv = 100000000;
	if (ra < ((3 * M_PI) / 2) && ra > M_PI_2)
	{
		cub3d->vx = ((int)cub3d->posX / UNIT) * UNIT - 0.0001;
		cub3d->vy = ((cub3d->posX - cub3d->vx) * (-tan(ra))) + cub3d->posY;
		cub3d->xo = -UNIT;
		cub3d->yo = -cub3d->xo * (-tan(ra));
	}
	else if (ra > ((3 * M_PI) / 2) || ra < M_PI_2)
	{
		cub3d->vx = ((int)cub3d->posX / UNIT) * UNIT + UNIT;
		cub3d->vy = ((cub3d->posX - cub3d->vx) * (-tan(ra))) + cub3d->posY;
		cub3d->xo = UNIT;
		cub3d->yo = -cub3d->xo * (-tan(ra));
	}
	else if (ra == 3 * M_PI_2 || ra == M_PI_2)
	{
		cub3d->vx = cub3d->posX;
		cub3d->vy = cub3d->posY;
		lim = cub3d->m_size_x;
	}
	dist_to_vertical_wall(cub3d, cub3d->xo, cub3d->yo, lim);
}
