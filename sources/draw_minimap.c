/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:51:41 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 17:51:55 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color)
{
	int	new_x;
	int	new_y;

	new_y = y * SIZEMINIMAP;
	while (new_y < (y * SIZEMINIMAP) + SIZEMINIMAP)
	{
		new_x = x * SIZEMINIMAP;
		while (new_x < (x * SIZEMINIMAP) + SIZEMINIMAP)
		{
			mlx_put_pixel(cub3d->minimap, new_x, new_y, color);
			new_x++;
		}
		new_y++;
	}
}

void	draw_minimap(t_cub3d *cub3d)
{
	int		x;
	int		y;

/* 	mlx_delete_image(cub3d->mlx, cub3d->minimap);
	cub3d->minimap = mlx_new_image(cub3d->mlx, WIDTH, GHEIGHT); */
	y = 0;
	while (y < cub3d->m_size_y)
	{
		x = 0;
		while (x < cub3d->m_size_x)
		{
			if (cub3d->map[y][x] == '0')
				draw_tile(cub3d, x, y, 0xFFFFFF88);
			else if (cub3d->map[y][x] == '1')
				draw_tile(cub3d, x, y, 0x88888888);
			x++;
		}
		y++;
	}
	draw_character(cub3d, 0xFF0000FF);
}
