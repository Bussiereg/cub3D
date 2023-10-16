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

void draw_laser(t_cub3d *cub3d)
{
	int r,dof;
	double rx,ry,mx,my,ra,xo,yo,atan;

	ra = cub3d->pos_angle;
	r = 0;
	while (r++ < 1)
	{
		// check Horizontal line
		dof = 0;
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
		else if (ra == 0 || ra == PI)
		{
			rx = cub3d->pos_x;
			ry = cub3d->pos_y;
			dof = 25;
		}
		// printf("xo: %f\nyo: %f\nrx: %f\nry: %f\npx: %f\npy: %f\nangle: %f\n\n", xo, yo, rx, ry, cub3d->pos_x, cub3d->pos_y, ra);
		while (dof < 25)
		{
			mx = (rx / UNIT);
			my = (ry / UNIT);
			if ((int)mx < 0 || (int)mx > cub3d->m_size_x)
				break;
			if ((int)my < 0 || (int)my > cub3d->m_size_y)
				break;
			if (cub3d->map[(int)my][(int)mx] == '1')
				break;
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
			printf("mx: %d\nmy: %d\n", (int)mx, (int)my);
		}
		cub3d->pos_char.x = (int)cub3d->pos_x;
		cub3d->pos_char.y = (int)cub3d->pos_y;
		cub3d->pos_char.color = 0x00FF00FF;
		cub3d->pos_wall.x = (int)rx;
		cub3d->pos_wall.y = (int)ry;
		cub3d->pos_wall.color = 0x00FF00FF;
		printf("char.x: %d\nchar.y: %d\nwall.x %d\nwall.y %d\n\n", (cub3d->pos_char.x / UNIT), (cub3d->pos_char.y / UNIT), (cub3d->pos_wall.x / UNIT), (cub3d->pos_wall.y / UNIT));
		draw_line(cub3d->pos_char, cub3d->pos_wall, cub3d->minimap);
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
