/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:30:29 by gbussier          #+#    #+#             */
/*   Updated: 2023/10/24 17:30:32 by gbussier         ###   ########.fr       */
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

double	distance(double ax, double ay, double bx, double by)
{
	double	result;

	result = sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)));
	return (result);
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
		if (cub3d->map[cub3d->my][cub3d->mx] == '1')
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
		if (cub3d->map[cub3d->my][cub3d->mx] == '1')
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

void	check_horizontal_line(t_cub3d *cub3d, double ra, int lim)
{
	cub3d->disth = 100000000;
	if (ra > M_PI) // looking up
	{
		cub3d->hy = ((int)cub3d->pos_y / UNIT) * UNIT - 0.0001;
		cub3d->hx = ((cub3d->pos_y - cub3d->hy) * (-1 / tan(ra)))
			+ cub3d->pos_x;
		cub3d->yo = -UNIT;
		cub3d->xo = -cub3d->yo * (-1 / tan(ra));
	}
	else if (ra < M_PI) // looking down
	{
		cub3d->hy = ((int)cub3d->pos_y / UNIT) * UNIT + UNIT;
		cub3d->hx = ((cub3d->pos_y - cub3d->hy)) * (-1 / tan(ra))
			+ cub3d->pos_x;
		cub3d->yo = UNIT;
		cub3d->xo = -cub3d->yo * (-1 / tan(ra));
	}
	else if (ra == 0 || ra == M_PI) // looking straight
	{
		cub3d->hx = cub3d->pos_x;
		cub3d->hy = cub3d->pos_y;
		lim = cub3d->m_size_y;
	}
	dist_to_horizontal_wall(cub3d, cub3d->xo, cub3d->yo, lim);
}

void	check_vertical_line(t_cub3d *cub3d, double ra, int lim)
{
	cub3d->distv = 100000000;
	if (ra < ((3 * M_PI) / 2) && ra > M_PI_2) // looking left
	{
		cub3d->vx = ((int)cub3d->pos_x / UNIT) * UNIT - 0.0001;
		cub3d->vy = ((cub3d->pos_x - cub3d->vx) * (-tan(ra))) + cub3d->pos_y;
		cub3d->xo = -UNIT;
		cub3d->yo = -cub3d->xo * (-tan(ra));
	}
	else if (ra > ((3 * M_PI) / 2) || ra < M_PI_2) // looking right
	{
		cub3d->vx = ((int)cub3d->pos_x / UNIT) * UNIT + UNIT;
		cub3d->vy = ((cub3d->pos_x - cub3d->vx) * (-tan(ra))) + cub3d->pos_y;
		cub3d->xo = UNIT;
		cub3d->yo = -cub3d->xo * (-tan(ra));
	}
	else if (ra == 3 * M_PI_2 || ra == M_PI_2) // looking straight up or down
	{
		cub3d->vx = cub3d->pos_x;
		cub3d->vy = cub3d->pos_y;
		lim = cub3d->m_size_x;
	}
	dist_to_vertical_wall(cub3d, cub3d->xo, cub3d->yo, lim);
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

void	raycaster(t_cub3d *cub3d, double ra, int ray)
{
	double	ca;
	double	tx;
	int		tile_d;
	int		pixel;
	double	line_height;

	ca = fix_angle(cub3d->pos_angle - ra);
	cub3d->final_d = cub3d->final_d * cos(ca);
	line_height = (HEIGHT * ((double)WIDTH / (double)HEIGHT)) / (cub3d->final_d / UNIT);
	if (cub3d->disth < cub3d->distv)
	{
		tile_d = (int)cub3d->wall_x / UNIT;
		tx = cub3d->wall_x - tile_d * UNIT;
		pixel = tx / UNIT * cub3d->S->height;
		if (ra < M_PI) // SOUTH wall
			draw_line_textu(line_height, ray, cub3d->S->height - pixel - 1,
				cub3d->S, cub3d);
		else // NORTH WALL
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
		if (ra <= M_PI_2 || ra >= (3 * M_PI_2)) // WEST wall
			draw_line_textu(line_height, ray, pixel, cub3d->E, cub3d);
		else // EAST WALL
			draw_line_textu(line_height, ray, cub3d->E->height - pixel - 1,
				cub3d->W, cub3d);
	}
}
