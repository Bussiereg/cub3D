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

void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color)
{
	int new_x;
	int new_y;

	new_y = y * UNIT;
	while (new_y < (y * UNIT) + UNIT)
	{
		new_x = x * UNIT;
		while (new_x < (x * UNIT) + UNIT)
		{
			if ((new_x == (x * UNIT) + UNIT -1) || (new_y == (y * UNIT) + UNIT -1))
				mlx_put_pixel(cub3d->minimap, new_x, new_y, 0x095275FF);
			else
				mlx_put_pixel(cub3d->minimap, new_x, new_y, color);
			new_x++;
		}
		new_y++;
	}
}
double distance(double ax, double ay, double bx, double by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * ( by - ay))));
}

void draw_laser(t_cub3d *cub3d)
{
	int r,dof;
	double rx,ry,ra,xo,yo;
	int mx, my;
	double atan;
	double ntan;
	double disth = 1000000;
	double hx = cub3d->pos_x;
	double hy = cub3d->pos_y;
	double distv = 1000000;
	double vx = cub3d->pos_x;
	double vy = cub3d->pos_y;


	ra = cub3d->pos_angle - DR * WIDTH / 2;
	r = -1;
	while (++r < WIDTH)
	{
		// check Horizontal line
	 	dof = 0;
		hx = cub3d->pos_x;
		hy = cub3d->pos_y;
		atan = -(1 / tan(ra));
		if (ra > PI) // looking up
		{
			ry = ((((int)cub3d->pos_y) / UNIT) * UNIT) - 0.0001;
			rx = ((cub3d->pos_y - ry) * atan) + cub3d->pos_x;
			yo = - UNIT;
			xo = - yo * atan;
		}
		else if (ra < PI) // looking down
		{
			ry = (((int)(cub3d->pos_y) / UNIT) * UNIT) + UNIT;
			rx = ((cub3d->pos_y - ry)) * atan + cub3d->pos_x;
			yo = UNIT;
			xo = - yo * atan;
		}
		else if (ra == 0 || ra == PI) // looking straight
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
		dof = 0;
		vx = cub3d->pos_x;
		vy = cub3d->pos_y;
		ntan = -tan(ra);
		if (ra < ((3 * PI) / 2) && ra > PI2) // looking left
		{
			rx = (((int)cub3d->pos_x / UNIT) * UNIT) - 0.0001;
			ry = ((cub3d->pos_x - rx) * ntan) + cub3d->pos_y;
			xo = - UNIT;
			yo = - xo * ntan;
		}
		else if (ra > ((3 * PI) / 2) || ra < PI2) // looking right
		{
			rx = (((int)cub3d->pos_x / UNIT) * UNIT) + UNIT;
			ry = ((cub3d->pos_x - rx) * ntan) + cub3d->pos_y;
			xo = UNIT;
			yo = - xo * ntan;
		}
		else if (ra == PI2 || ra == ((3 * PI) / 2)) //looking straight up or down
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
		if (distv < disth)
		{
			ry = vy;
			rx = vx;
		}
		if (disth < distv)
		{
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

		double final_d = distance(cub3d->pos_x, cub3d->pos_y, rx, ry);
		float ca = cub3d->pos_angle - ra;
		if (ca < 0)
			ca += 2* PI;
		if (ca > 2* PI)
			ca -= 2* PI;
		final_d = final_d * cos(ca);
		//printf("distance = %f\n", final_d / UNIT);
	//	printf("rx = %f\n", rx);

	//	printf("ra = %f\n", ra);
		if (disth < distv)
		{
			int tile_d = (int)rx / UNIT;
			//printf("tile_d = %d\n", tile_d);
			double tx = rx - tile_d * UNIT;
		//	printf("tx = %f\n", tx);
			int pixel = tx / UNIT * cub3d->S->height;
			if (ra < PI) // SOUTH wall
				draw_line_textu(HEIGHT / (final_d / UNIT), r, cub3d->S->height - pixel - 1, cub3d->S, cub3d);
			else         // NORTH WALL
				draw_line_textu(HEIGHT / (final_d / UNIT), r, pixel, cub3d->N, cub3d);
		}
		else
		{
			int tile_d = (int)ry / UNIT;
			//printf("tile_d = %d\n", tile_d);
			double tx = ry - tile_d * UNIT;
		//	printf("tx = %f\n", tx);
			int pixel = tx / UNIT * cub3d->S->height;
			if (ra < PI2 || ra > PI3) // WEST wall
				draw_line_textu(HEIGHT / (final_d / UNIT), r, pixel, cub3d->E, cub3d);
			else         // EAST WALL
				draw_line_textu(HEIGHT / (final_d / UNIT), r, cub3d->S->height - pixel - 1, cub3d->W, cub3d);
		}
		ra = ra  + DR;

	}
}

void	draw_character(t_cub3d *cub3d, unsigned int color)
{
	int new_x;
	int new_y;
	int x;
	int y;
	int i;
	int j;

	x = cub3d->pos_x;
	y = cub3d->pos_y;
	new_x = cub3d->pos_x - 3;
	new_y = cub3d->pos_y - 3;
	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			mlx_put_pixel(cub3d->minimap, new_x + i, new_y + j, color);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (j < (20))
	{
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j, y + cub3d->pos_dy * j, color);
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j - 1, y + cub3d->pos_dy * j, color);
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j, y + cub3d->pos_dy * j - 1, color);
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j, y + cub3d->pos_dy * j + 1, color);
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j + 1, y + cub3d->pos_dy * j, color);
		j++;
	}
	
}

void	draw_minimap_background(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < cub3d->m_size_y)
	{
		x = 0;
		while (x < cub3d->m_size_x)
		{
			//draw_rectangle();
			if (cub3d->map[y][x] == '0')
				draw_tile(cub3d, x, y, 0xFFFFFFFF);
			else
				draw_tile(cub3d, x, y, 0x030209FF);
			x++;
		}
		y++;
	}
	// DRAW CHARACTER POINT
	draw_character(cub3d, 0xFF0000FF);
	draw_laser(cub3d);
	mlx_image_to_window(cub3d->mlx, cub3d->minimap, 0, 0);
}
