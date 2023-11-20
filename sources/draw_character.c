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

#include "cub3d.h"

void	draw_direction(t_cub3d *cub3d, unsigned int color)
{
	int	j;

	j = 0;
	while (j < (4))
	{
		mlx_put_pixel(cub3d->minimap, cub3d->posX + cub3d->dirX * j,
			cub3d->posY + cub3d->dirY * j, color);
		mlx_put_pixel(cub3d->minimap, cub3d->posX + cub3d->dirX * j - 1,
			cub3d->posY + cub3d->dirY * j, color);
		mlx_put_pixel(cub3d->minimap, cub3d->posX + cub3d->dirX * j,
			cub3d->posY + cub3d->dirY * j - 1, color);
		mlx_put_pixel(cub3d->minimap, cub3d->posX + cub3d->dirX * j,
			cub3d->posY + cub3d->dirY * j + 1, color);
		mlx_put_pixel(cub3d->minimap, cub3d->posX + cub3d->dirX * j + 1,
			cub3d->posY + cub3d->dirY * j, color);
		j++;
	}
}

void	draw_character(t_cub3d *cub3d, unsigned int color)
{
	int	new_x;
	int	new_y;
	int	i;
	int	j;

	new_x = cub3d->posX - 1;
	new_y = cub3d->posY - 1;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
			mlx_put_pixel(cub3d->minimap, new_x + i++, new_y + j++, color);
	}
	draw_direction(cub3d, color);
}
