/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_viewport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:36 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:39 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_textu(double line_height, int text_x_pos,
		mlx_image_t *text, t_cub3d *cub3d)
{
	int	i;
	int	a;
	int	b;
	int	col;

	b = GHEIGHT / 2 + line_height / 2;
	a = b - line_height;
	i = 0;
	while (a < b)
	{
		if (cub3d->ray >= 0 && a >= 0 && cub3d->ray < WIDTH && a < GHEIGHT)
		{
			col = calc_pix_color(i, text, text_x_pos, line_height + 1);
			if (col != 0)
				mlx_put_pixel(cub3d->viewport, cub3d->ray, a, col);
		}
		a++;
		i++;
	}
}

void	draw_game(t_cub3d *cub3d)
{
	cub3d->ray = 0;
	while (cub3d->ray < WIDTH)
	{
		raycaster_calculus(cub3d);
		wall_distance(cub3d);
		raycaster(cub3d);
		cub3d->ray++;
	}
}
