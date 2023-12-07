/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:32 by jubernar          #+#    #+#             */
/*   Updated: 2023/01/06 15:55:35 by jubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_cub3d *cub3d)
{
	int	x;
	int	y;

	if (cub3d->background)
		mlx_delete_image(cub3d->mlx, cub3d->background);
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->background)
		terminate("new rendering memory fail", cub3d, 1, 2);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(cub3d->background, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	render_viewport(t_cub3d *cub3d)
{
	if (cub3d->viewport)
		mlx_delete_image(cub3d->mlx, cub3d->viewport);
	cub3d->viewport = mlx_new_image(cub3d->mlx, WIDTH, GHEIGHT);
	if (!cub3d->viewport)
		terminate("new rendering memory fail", cub3d, 1, 2);
	draw_ceiling(cub3d);
	draw_floor(cub3d);
	draw_game(cub3d);
}

void	render(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	move_around(cub3d);
	render_background(cub3d);
	render_viewport(cub3d);
	mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0);
	mlx_set_instance_depth(cub3d->background->instances, 1);
	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 115);
	mlx_set_instance_depth(cub3d->viewport->instances, 2);
}
