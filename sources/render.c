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
	mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0);
	mlx_set_instance_depth(cub3d->background->instances, 1);
}

void	render_viewport(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->viewport);
	cub3d->viewport = mlx_new_image(cub3d->mlx, WIDTH, GHEIGHT);
	draw_ceiling(cub3d);
	draw_floor(cub3d);
	draw_game(cub3d);
	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 115);
	mlx_set_instance_depth(cub3d->viewport->instances, 2);
}

void	set_opacity(mlx_image_t *img, int i)
{
	unsigned int	p;

	p = 0;
	while (p < img->height * img->width)
	{
		//img->pixels[(p * (sizeof(int32_t)) + 3)] = i;
		if (img->pixels[(p * (sizeof(int32_t)) + 3)] != 0)
		{
			ft_printf("%d  ", img->pixels[(p * (sizeof(int32_t)) + 3)]);
			img->pixels[(p * (sizeof(int32_t)) + 3)] = i;
		}
		p++;
		(void)i;
	}
}

void	render_intro(t_cub3d *cub3d)
{
/* 	mlx_texture_t	*texture; */
	if (cub3d->frame < 150)
	{
		set_opacity(cub3d->intro, 255 - cub3d->frame);
		mlx_image_to_window(cub3d->mlx, cub3d->intro, 0, 0);
		mlx_set_instance_depth(cub3d->intro->instances, 0);
	}
/* 	texture = mlx_load_png("./texture/intro.png");
	cub3d->intro = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture); */
}

void	render(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	cub3d->frame++;
	printf("frame = %d\n", cub3d->frame);
	render_intro(cub3d);
	render_background(cub3d);
	render_viewport(cub3d);
	draw_minimap(cub3d);
}
