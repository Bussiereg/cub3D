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

void	set_opacity(mlx_image_t *img, int alpha)
{
	unsigned int	i;

	i = 0;
	while (i < img->height * img->width)
	{
		if (img->pixels[((i) * (sizeof(int32_t)) + 3)] != 0)
		{
			img->pixels[((i) * (sizeof(int32_t)) + 3)] = alpha;
			//ft_printf("%d  ", img->pixels[((i) * (sizeof(int32_t)) + 3)]);
		}
		i++;
	}
}

void	render_intro(t_cub3d *cub3d)
{
	mlx_texture_t	*texture;
	int	alpha;

	alpha = 255 - cub3d->frame * 2.5;
	mlx_delete_image(cub3d->mlx, cub3d->intro);
	texture = mlx_load_png("./texture/intro.png");
	cub3d->intro = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
	ft_printf("fram = %d \n", cub3d->frame);
	ft_printf("alph = %d \n", alpha);
	if (alpha >= 0)
	{
		set_opacity(cub3d->intro, alpha);
		mlx_image_to_window(cub3d->mlx, cub3d->intro, 0, 0);
	}
	//mlx_set_instance_depth(cub3d->intro->instances, 3);

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

void	render(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	cub3d->frame++;
	if (cub3d->frame < 255)
		render_intro(cub3d);
	render_background(cub3d);
	render_viewport(cub3d);
	draw_minimap(cub3d);
}
