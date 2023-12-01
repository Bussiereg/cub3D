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
	int	p;

	mlx_delete_image(cub3d->mlx, cub3d->background);
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	p = 0;
	ft_bzero(cub3d->background->pixels, HEIGHT * WIDTH);
	while (p < HEIGHT * WIDTH)
	{
		cub3d->background->pixels[(p * (sizeof(int32_t)) + 3)] = 0xFF;
		p++;
	}
}

void	set_opacity(mlx_image_t *img, int alpha)
{
	unsigned int	i;

	i = 0;
	while (i < img->height * img->width)
	{
		if (img->pixels[((i) * (sizeof(int32_t)) + 3)] != 0)
			img->pixels[((i) * (sizeof(int32_t)) + 3)] = alpha;
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
	if (255 - cub3d->frame * 2.5 >= 0)
	{
		set_opacity(cub3d->intro, alpha);
	}
}

void	render_viewport(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->viewport);
	mlx_delete_image(cub3d->mlx, cub3d->sprite_img);
	cub3d->viewport = mlx_new_image(cub3d->mlx, WIDTH, GHEIGHT);
	cub3d->sprite_img = mlx_new_image(cub3d->mlx, WIDTH, GHEIGHT);
	draw_ceiling(cub3d);
	draw_floor(cub3d);
	draw_game(cub3d);
	if (++cub3d->key_frame > 36)
		cub3d->key_frame = 1;
	//printf("%d\n", cub3d->key_frame);
}

void	move_around(t_cub3d *cub3d)
{
	if (cub3d->move_up == 1)
		moving_up(cub3d);
	if (cub3d->move_down == 1)
		moving_down(cub3d);
	if (cub3d->move_left == 1)
		moving_left(cub3d);
	if (cub3d->move_right == 1)
		moving_right(cub3d);
	if (cub3d->rotate_right == 1)
		rotating_right(cub3d);
	if (cub3d->rotate_left == 1)
		rotating_left(cub3d);
}

void	render_end(t_cub3d *cub3d)
{
	int	y;

	if (cub3d->end_start == 0)
		cub3d->end_start = cub3d->frame;
	y = (cub3d->frame - cub3d->end_start) * 2;

	if (!cub3d->end_img)
		mlx_delete_image(cub3d->mlx, cub3d->end_img);
	cub3d->end_img = mlx_new_image(cub3d->mlx, WIDTH, GHEIGHT);
	ft_memset(cub3d->end_img->pixels, 255, WIDTH * GHEIGHT * 4);
	if (y <= 255)
		set_opacity(cub3d->end_img, y);
}

void	render(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	cub3d->frame++;
	if (cub3d->frame < 255)
		render_intro(cub3d);
	move_around(cub3d);
	render_background(cub3d);
	render_viewport(cub3d);
	draw_minimap(cub3d);
	if (cub3d->end == 1)
		render_end(cub3d);
	//background
	mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0);
	mlx_set_instance_depth(cub3d->background->instances, 1);
	// viewport
	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 115);
	mlx_set_instance_depth(cub3d->viewport->instances, 2);
	// sprite
	mlx_image_to_window(cub3d->mlx, cub3d->sprite_img, 0, 115);
	mlx_set_instance_depth(cub3d->sprite_img->instances, 3);
	// minimap
	mlx_image_to_window(cub3d->mlx, cub3d->minimap, 0, 0);
	mlx_set_instance_depth(cub3d->minimap->instances, 4);
	// end
	if (cub3d->end == 1)
	{
		mlx_image_to_window(cub3d->mlx, cub3d->end_img, 0, 115);
		mlx_set_instance_depth(cub3d->end_img->instances, 5);
	}
	// intro
	if (255 - cub3d->frame * 2.5 >= 0)
	{
		mlx_image_to_window(cub3d->mlx, cub3d->intro, 0, 0);
		mlx_set_instance_depth(cub3d->intro->instances, 6);
	}
}
