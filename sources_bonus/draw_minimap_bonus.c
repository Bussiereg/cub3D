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

#include "cub3d_bonus.h"

void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color1,  unsigned int color2)
{
	int	new_x;
	int	new_y;

	new_y = y * SIZEMINIMAP;
	while (new_y < (y * SIZEMINIMAP) + SIZEMINIMAP)
	{
		new_x = x * SIZEMINIMAP;
		while (new_x < (x * SIZEMINIMAP) + SIZEMINIMAP)
		{
			if (new_x % SIZEMINIMAP == 0 || new_y % SIZEMINIMAP == 0)
				mlx_put_pixel(cub3d->minimap, new_x, new_y, color2);
			else
				mlx_put_pixel(cub3d->minimap, new_x, new_y, color1);
			new_x++;
		}
		new_y++;
	}
}

void	draw_minimap(t_cub3d *cub3d)
{
	int		x;
	int		y;

	mlx_delete_image(cub3d->mlx, cub3d->minimap);
	cub3d->minimap = mlx_new_image(cub3d->mlx, cub3d->m_size_x * SIZEMINIMAP, cub3d->m_size_y * SIZEMINIMAP);
	if (cub3d->minimap_on % 2 == 1)
	{
		y = 0;
		while (y < cub3d->m_size_y)
		{
			x = 0;
			while (x < cub3d->m_size_x)
			{
				if (cub3d->map[y][x] == '0')
					draw_tile(cub3d, x, y, 0x000000FF, 0x19b919FF);
				else if (cub3d->map[y][x] == '1')
					draw_tile(cub3d, x, y, 0x19b919FF, 0x000000FF);
				else if (cub3d->map[y][x] == 'c')
					draw_tile(cub3d, x, y, 0xFFFF00FF, 0x19b919FF);
				else if (cub3d->map[y][x] == 'D')
					draw_tile(cub3d, x, y, 0x00FF00FF, 0x19b919FF);
				x++;
			}
			y++;
		}
		draw_character(cub3d, 0xFF0000FF);
	}
}
