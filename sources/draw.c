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
				mlx_put_pixel(cub3d->minimap, x, y, 0);
			else
				mlx_put_pixel(cub3d->minimap, x, y, 200);
			x++;
		}
		y++;
	}

	// DRAW CHARACTER POINT
	// 5 and 10 are the corrdinate of the character
		mlx_put_pixel(cub3d->minimap, 5, 10, 0xFF0000FF);
	mlx_image_to_window(cub3d->mlx, cub3d->minimap, 0, 0);
}
