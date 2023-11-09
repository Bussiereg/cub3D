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
	calc_grad_steps(HEIGHT / 2, sky_darker, sky, &*rgba);
	y = 0;
	while (y < HEIGHT / 2)
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

	y = HEIGHT / 2;
	while (y < HEIGHT)
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

	a = HEIGHT / 2 - line_height / 2;
	b = HEIGHT / 2 + line_height / 2;
	i = 0;
	while (a < b)
	{
		if (cub3d->ray >= 0 && a >= 0 && cub3d->ray < WIDTH && a < HEIGHT)
			mlx_put_pixel(cub3d->viewport, cub3d->ray, a, calc_pix_color(i,
					text, text_x_pos, line_height + 1));
		a++;
		i++;
	}
}

void	draw_game(t_cub3d *cub3d)
{
	double	ray_angle;

	ray_angle = cub3d->pos_angle - DR * WIDTH / 2;
	cub3d->ray = -1;
	cub3d->vx = cub3d->pos_x;
	cub3d->vy = cub3d->pos_y;
	cub3d->hx = cub3d->pos_x;
	cub3d->hy = cub3d->pos_y;
	cub3d->xo = 0;
	cub3d->yo = 0;
	while (++cub3d->ray <= WIDTH)
	{
		ray_angle = fix_angle(ray_angle);
		check_horizontal_line(cub3d, ray_angle, 0);
		check_vertical_line(cub3d, ray_angle, 0);
		calculate_wall_distance(cub3d);
		raycaster(cub3d, ray_angle);
		ray_angle = ray_angle + DR;
	}
}
