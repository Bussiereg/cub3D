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


void	render_skybox(t_cub3d *cub3d)
{
	int	i;

	i = WIDTH * 4 * cub3d->pos_angle / 6.283185 * -1;
	mlx_image_to_window(cub3d->mlx, cub3d->t_sky, i, 0);
	if (i < WIDTH * 3 * -1)
	{
		mlx_image_to_window(cub3d->mlx, cub3d->t_sky, -1 * (WIDTH * -4 - i), 0);
	}
	
}

void	render_viewport(t_cub3d *cub3d)
{
	ft_bzero(cub3d->viewport->pixels, cub3d->viewport->height *cub3d->viewport->width*4);
	draw_floor(cub3d);
	draw_game(cub3d);
	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 0);
}

void	render(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	mlx_image_to_window(cub3d->mlx, cub3d->t_intro, 0, 0);
	render_skybox(cub3d);
	render_viewport(cub3d);
	draw_ceiling(cub3d);
}
