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
				mlx_put_pixel(cub3d->minimap, new_x, new_y, 0x0000FFFF);
			else
				mlx_put_pixel(cub3d->minimap, new_x, new_y, color);
			new_x++;
		}
		new_y++;
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
	while (j < (30))
	{
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j, y + cub3d->pos_dy * j, color + 40);
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j - 1, y + cub3d->pos_dy * j, color + 40);
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j, y + cub3d->pos_dy * j - 1, color + 40);
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j, y + cub3d->pos_dy * j + 1, color + 40);
		mlx_put_pixel(cub3d->minimap, x + cub3d->pos_dx * j + 1, y + cub3d->pos_dy * j, color + 40);
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
				draw_tile(cub3d, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	// DRAW CHARACTER POINT
	draw_character(cub3d, 0xFF0000FF);
	mlx_image_to_window(cub3d->mlx, cub3d->minimap, 0, 0);
}
