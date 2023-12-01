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

int	draw_sky(t_cub3d *cub3d)
{
	int		x;
	int		y;
	float	rgba[4];
	int		sky_darker;
	int		sky;

	sky = cub3d->color_c;
	sky_darker = 0x000910FF;
	calc_grad_steps(GHEIGHT / 2, sky_darker, sky, &*rgba);
	y = 0;
	while (y < GHEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH * 2)
		{
			mlx_put_pixel(cub3d->viewport, x, y, calc_grad_color(y, sky_darker,
					&*rgba));
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_ceiling(t_cub3d *cub3d)
{
	draw_sky(cub3d);
	return (0);
}

int	draw_floor(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = GHEIGHT / 2;
	while (y < GHEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(cub3d->viewport, x, y, cub3d->color_f);
			x++;
		}
		y++;
	}
	return (0);
}

void	draw_line_textu(double line_height, int text_x_pos, mlx_image_t *text,
		t_cub3d *cub3d)
{
	int	i;
	int	a;
	int	b;
	int	col;

	b = GHEIGHT / 2 + line_height / cub3d->wall_height / 2;
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

void	draw_door_line_textu(double line_height, int text_x_pos, mlx_image_t *text,
		t_cub3d *cub3d)
{
	int	i;
	int	a;
	int	b;
	int	y;
	int	col;

	y = 0;
	if (cub3d->door_open == 1)
	{
		if (cub3d->door_open_start == 0)
			cub3d->door_open_start = cub3d->frame;
		y = cub3d->frame - cub3d->door_open_start;
	}
	b = GHEIGHT / 2 + line_height / cub3d->wall_height / 2;
	a = b - line_height;
	a += line_height * 0.008 * y;
	if (a > b)
		*cub3d->door = '0';
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
		doorcaster(cub3d);
		cub3d->ray++;
	}
}
