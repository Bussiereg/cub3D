/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:32 by jubernar          #+#    #+#             */
/*   Updated: 2023/01/06 15:55:35 by jubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double fix_angle(double a)
{
	if (a > (2 * M_PI))
		a -= (2 * M_PI);
	else if (a <= 0)
		a += (2 * M_PI);
	return (a);
}

double distance(double ax, double ay, double bx, double by)
{
	double result;

	result = sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * ( by - ay)));
	return (result);
}

void draw_laser(t_cub3d *cub3d)
{
	int r,dof;
	double rx,ry,ra,xo,yo;
	int mx, my;
	double atan;
	double ntan;
	double disth;
	double hx;
	double hy;
	double distv;
	double vx;
	double vy;

	ra = cub3d->pos_angle - DR * WIDTH / 2;
	r = -1;
	while (++r <= WIDTH)
	{
		ra = fix_angle(ra);
		// check Horizontal line
		disth = 100000000;
		hx = cub3d->pos_x;
		hy = cub3d->pos_y;
	 	dof = 0;
		atan = -(1 / tan(ra));
		if (ra > M_PI) // looking up
		{
			ry = ((int)cub3d->pos_y / UNIT) * UNIT - 0.0001;
			rx = ((cub3d->pos_y - ry) * atan) + cub3d->pos_x;
			yo = - UNIT;
			xo = - yo * atan;
		}
		else if (ra < M_PI) // looking down
		{
			ry = ((int)cub3d->pos_y / UNIT) * UNIT + UNIT;
			rx = ((cub3d->pos_y - ry)) * atan + cub3d->pos_x;
			yo = UNIT;
			xo = - yo * atan;
		}
		else if (ra == 0 || ra == M_PI) // looking straight
		{
			rx = cub3d->pos_x;
			ry = cub3d->pos_y;
			dof = cub3d->m_size_y;
		}
		while (dof < cub3d->m_size_y)
		{
			mx = ((int)rx / UNIT);
			my = ((int)ry / UNIT);
			if (mx < 0)
				mx = 0;
			else if (mx >= cub3d->m_size_x - 1)
				mx = cub3d->m_size_x - 1;
			if (my < 0)
				my = 0;
			else if (my >= cub3d->m_size_y - 1)
				my = cub3d->m_size_y - 1;
			if (cub3d->map[my][mx] == '1')
			{
 				hx = rx;
				hy = ry;
				disth = distance(cub3d->pos_x, cub3d->pos_y, hx, hy);
				break;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		// check vertical line
		distv = 100000000;
		vx = cub3d->pos_x;
		vy = cub3d->pos_y;
		dof = 0;
		ntan = -tan(ra);
		if (ra < ((3 * M_PI) / 2) && ra > M_PI_2) // looking left
		{
			rx = ((int)cub3d->pos_x / UNIT) * UNIT - 0.0001;
			ry = ((cub3d->pos_x - rx) * ntan) + cub3d->pos_y;
			xo = - UNIT;
			yo = - xo * ntan;
		}
		else if (ra > ((3 * M_PI) / 2) || ra < M_PI_2) // looking right
		{
			rx = ((int)cub3d->pos_x / UNIT) * UNIT + UNIT;
			ry = ((cub3d->pos_x - rx) * ntan) + cub3d->pos_y;
			xo = UNIT;
			yo = - xo * ntan;
		}
		else if (ra == 3 * M_PI_2 || ra == M_PI_2) //looking straight up or down
		{
			rx = cub3d->pos_x;
			ry = cub3d->pos_y;
			dof = cub3d->m_size_x;
		}
		while (dof < cub3d->m_size_x)
		{
			mx = ((int)rx / UNIT);
			my = ((int)ry / UNIT);
			if (mx < 0)
				mx = 0;
			if (mx >= cub3d->m_size_x - 1)
				mx = cub3d->m_size_x - 1;
			if (my < 0)
				my = 0;
			if (my >= cub3d->m_size_y - 1)
				my = cub3d->m_size_y - 1;
			if (cub3d->map[my][mx] == '1')
			{
				vx = rx;
				vy = ry;
				distv = distance(cub3d->pos_x, cub3d->pos_y, vx, vy);
				break;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		double final_d;
		if (distv < disth)
		{
			final_d = distv;
			ry = vy;
			rx = vx;
		}
		if (disth <= distv)
		{
			final_d = disth;
			ry = hy;
			rx = hx;
		}
		cub3d->pos_char.x = (int)cub3d->pos_x;
		cub3d->pos_char.y = (int)cub3d->pos_y;
		cub3d->pos_char.color = 0xFF8800FF;
		cub3d->pos_wall.x = (int)rx;
		cub3d->pos_wall.y = (int)ry;
		cub3d->pos_wall.color = 0xFFC380FF;
		draw_line(cub3d->pos_char, cub3d->pos_wall, cub3d->minimap);

/* 		double final_d = distance(cub3d->pos_x, cub3d->pos_y, rx, ry); */
		// printf("4: rx: %f  ry: %f distfin: %f\n", rx / UNIT, ry / UNIT, final_d);
/* 		double ca = cub3d->pos_angle - ra; */
		double ca = cub3d->pos_angle - ra;
		ca = fix_angle(ca);
		final_d = final_d * cos(ca);
		printf("final distance is: %f\n", final_d);
		double tx = 0;
		if (disth < distv)
		{
			int tile_d = (int)rx / UNIT;
			tx = rx - tile_d * UNIT;
			int pixel = tx / UNIT * cub3d->S->height;
			if (ra < M_PI) // SOUTH wall
				draw_line_textu(HEIGHT / (final_d / UNIT), r, cub3d->S->height - pixel - 1, cub3d->S, cub3d);
			else         // NORTH WALL
			{
				int pixel = tx / UNIT * cub3d->N->height;
				draw_line_textu(HEIGHT / (final_d / UNIT), r, pixel, cub3d->N, cub3d);
			}
		}
		else
		{
			int tile_d = (int)ry / UNIT;
			tx = ry - tile_d * UNIT;
			int pixel = tx / UNIT * cub3d->S->height;
			if (ra <= M_PI_2 || ra >= (3 * M_PI_2)) // WEST wall
				draw_line_textu(HEIGHT / (final_d / UNIT), r, pixel, cub3d->E, cub3d);
			else         // EAST WALL
				draw_line_textu(HEIGHT / (final_d / UNIT), r, cub3d->E->height - pixel - 1, cub3d->W, cub3d);
		}
		ra = ra + DR;
	}
}

void display(t_cub3d *cub3d);
{
	draw_minimap(cub3d);
	// draw_game(cub3d);
}