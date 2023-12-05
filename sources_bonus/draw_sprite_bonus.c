/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:15:25 by gbussier          #+#    #+#             */
/*   Updated: 2023/12/04 13:15:27 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_sprite_motor(t_cub3d *cub3d, int stripe, int a, int b)
{
	int	k;
	int	color;
	int	texx;

	if (cub3d->transform_y > 0 && stripe > 0 && stripe < WIDTH - 1
		&& cub3d->transform_y < cub3d->zbuffer[stripe]
		&& cub3d->draw_end_x > cub3d->draw_start_x)
	{
		texx = (((double)(stripe - cub3d->draw_start_x) / (cub3d->draw_end_x
						- cub3d->draw_start_x))
				* (key_frame_selector(cub3d))->width);
		a = GHEIGHT / 2 - (cub3d->draw_end_y - cub3d->draw_start_y) / 2;
		b = GHEIGHT / 2 + (cub3d->draw_end_y - cub3d->draw_start_y) / 2;
		k = 0;
		while (a < b && a < GHEIGHT)
		{
			color = calc_pix_color(k, key_frame_selector(cub3d),
					texx, (cub3d->draw_end_y - cub3d->draw_start_y) + 1);
			if (color != 0)
				mlx_put_pixel(cub3d->sprite_img, stripe, a, color);
			a++;
			k++;
		}
	}
}

void	draw_sprite(t_cub3d *cub3d, int a, int b)
{
	int	stripe;

	stripe = cub3d->draw_start_x;
	while (stripe < cub3d->draw_end_x)
	{
		draw_sprite_motor(cub3d, stripe, a, b);
		stripe++;
	}
}

void	sprite_init(t_cub3d *cub3d, int i)
{
	cub3d->flag2 = cub3d->spriteorder[i];
	cub3d->sprite_x = cub3d->sprite[cub3d->spriteorder[i]].x - cub3d->posx;
	cub3d->sprite_y = cub3d->sprite[cub3d->spriteorder[i]].y - cub3d->posy;
	cub3d->invdet = 1.0 / (cub3d->plane_x * cub3d->dir_y
			- cub3d->dir_x * cub3d->plane_y);
	cub3d->transform_x = cub3d->invdet * (cub3d->dir_y
			* cub3d->sprite_x - cub3d->dir_x * cub3d->sprite_y);
	cub3d->transform_y = cub3d->invdet * (-cub3d->plane_y
			* cub3d->sprite_x + cub3d->plane_x * cub3d->sprite_y);
	cub3d->sprite_screen_x = (int)((WIDTH / 2)
			* (1 + cub3d->transform_x / cub3d->transform_y));
	cub3d->sprite_height = abs((int)(GHEIGHT / (cub3d->transform_y)));
	cub3d->draw_start_y = -cub3d->sprite_height / 2 + GHEIGHT / 2;
	cub3d->draw_end_y = cub3d->sprite_height / 2 + cub3d->viewport->height / 2;
	cub3d->sprite_width = abs((int)(GHEIGHT / (cub3d->transform_y)));
	cub3d->draw_start_x = -cub3d->sprite_width / 2 + cub3d->sprite_screen_x;
	cub3d->draw_end_x = cub3d->sprite_width / 2 + cub3d->sprite_screen_x;
}

void	sprite_casting(t_cub3d *cub3d)
{
	int	i;

	sort_sprite(cub3d);
	i = 0;
	while (i < NUMSPRITES)
	{
		if (cub3d->sprite[cub3d->spriteorder[i]].flag == 0)
			i++;
		else
		{
			sprite_init(cub3d, i);
			draw_sprite(cub3d, 0, 0);
			i++;
		}
	}
}
