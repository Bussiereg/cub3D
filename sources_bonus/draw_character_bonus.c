/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:10:08 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:10:10 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_direction(t_cub3d *cub3d, unsigned int color)
{
	int	j;

	j = 0;
	while (j < 5)
	{
		draw_pixel(cub3d->minimap, cub3d->posx * SIZEMINIMAP + cub3d->dir_x
			* j, cub3d->posy * SIZEMINIMAP + cub3d->dir_y * j, color);
		draw_pixel(cub3d->minimap, cub3d->posx * SIZEMINIMAP + cub3d->dir_x
			* j - 1, cub3d->posy * SIZEMINIMAP + cub3d->dir_y * j, color);
		draw_pixel(cub3d->minimap, cub3d->posx * SIZEMINIMAP + cub3d->dir_x
			* j, cub3d->posy * SIZEMINIMAP + cub3d->dir_y * j - 1, color);
		draw_pixel(cub3d->minimap, cub3d->posx * SIZEMINIMAP + cub3d->dir_x
			* j, cub3d->posy * SIZEMINIMAP + cub3d->dir_y * j + 1, color);
		draw_pixel(cub3d->minimap, cub3d->posx * SIZEMINIMAP + cub3d->dir_x
			* j + 1, cub3d->posy * SIZEMINIMAP + cub3d->dir_y * j, color);
		j++;
	}
}

void	draw_character(t_cub3d *cub3d, unsigned int color)
{
	int	new_x;
	int	new_y;
	int	i;
	int	j;

	new_x = cub3d->posx * SIZEMINIMAP;
	new_y = cub3d->posy * SIZEMINIMAP;
	i = 0;
	while (i++ < 1)
	{
		j = 0;
		while (j < 1)
			draw_pixel(cub3d->minimap, new_x + i, new_y + j++, color);
	}
}
