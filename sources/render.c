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

	mlx_delete_image(cub3d->mlx, cub3d->background);
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_put_pixel(cub3d->background, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	render_viewport(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->viewport);
	cub3d->viewport = mlx_new_image(cub3d->mlx, WIDTH, GHEIGHT);
	draw_ceiling(cub3d);
	draw_floor(cub3d);
	draw_game(cub3d);
}

void	render(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	render_background(cub3d);
	render_viewport(cub3d);
	draw_minimap(cub3d);
	//background
	mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0);
	mlx_set_instance_depth(cub3d->background->instances, 1);
	// viewport
	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 115);
	mlx_set_instance_depth(cub3d->viewport->instances, 2);
	// minimap
	mlx_image_to_window(cub3d->mlx, cub3d->minimap, 0, 0);
	mlx_set_instance_depth(cub3d->minimap->instances, 3);
	
}
