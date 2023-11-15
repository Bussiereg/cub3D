/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:19:36 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:19:38 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance(double ax, double ay, double bx, double by)
{
	double	result;

	result = sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)));
	return (result);
}

void	calculate_wall_distance(t_cub3d *cub3d)
{
	if (cub3d->distv < cub3d->disth)
	{
		cub3d->final_d = cub3d->distv;
		cub3d->wall_y = cub3d->vy;
		cub3d->wall_x = cub3d->vx;
	}
	if (cub3d->disth <= cub3d->distv)
	{
		cub3d->final_d = cub3d->disth;
		cub3d->wall_y = cub3d->hy;
		cub3d->wall_x = cub3d->hx;
	}
}

void	dist_to_vertical_wall(t_cub3d *cub3d, double xo, double yo, int lim)
{
	while (lim < cub3d->m_size_x)
	{
		cub3d->mx = ((int)cub3d->vx / UNIT);
		cub3d->my = ((int)cub3d->vy / UNIT);
		if (cub3d->mx < 0)
			cub3d->mx = 0;
		if (cub3d->my < 0)
			cub3d->my = 0;
		if (cub3d->my >= cub3d->m_size_y - 1)
			cub3d->my = cub3d->m_size_y - 1;
		if (cub3d->mx >= cub3d->m_size_x - 1)
			cub3d->mx = cub3d->m_size_x - 1;
		if (cub3d->map[cub3d->my][cub3d->mx] == '1' || cub3d->map[cub3d->my][cub3d->mx] == '2')
		{
			cub3d->distv = distance(cub3d->pos_x, cub3d->pos_y, cub3d->vx,
					cub3d->vy);
			break ;
		}
		else
		{
			cub3d->vx += xo;
			cub3d->vy += yo;
			lim++;
		}
	}
}

void	dist_to_horizontal_wall(t_cub3d *cub3d, double xo, double yo, int lim)
{
	while (lim < cub3d->m_size_y)
	{
		cub3d->mx = ((int)cub3d->hx / UNIT);
		cub3d->my = ((int)cub3d->hy / UNIT);
		if (cub3d->mx < 0)
			cub3d->mx = 0;
		else if (cub3d->mx >= cub3d->m_size_x - 1)
			cub3d->mx = cub3d->m_size_x - 1;
		if (cub3d->my < 0)
			cub3d->my = 0;
		else if (cub3d->my >= cub3d->m_size_y - 1)
			cub3d->my = cub3d->m_size_y - 1;
		if (cub3d->map[cub3d->my][cub3d->mx] == '1' ||cub3d->map[cub3d->my][cub3d->mx] == '2')
		{
			cub3d->disth = distance(cub3d->pos_x, cub3d->pos_y, cub3d->hx,
					cub3d->hy);
			break ;
		}
		else
		{
			cub3d->hx += xo;
			cub3d->hy += yo;
			lim++;
		}
	}
}
