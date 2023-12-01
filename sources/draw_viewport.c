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
			set_pixel_img(cub3d->viewport, x, y, calc_grad_color(y, sky_darker,
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
			set_pixel_img(cub3d->viewport, x, y, cub3d->color_f);
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
				set_pixel_img(cub3d->viewport, cub3d->ray, a, col);
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
				set_pixel_img(cub3d->viewport, cub3d->ray, a, col);
		}
		a++;
		i++;
	}
}

int 	max_double(double *spriteDistance)
{
	int pos;
	int i;
	double temp;

	temp = spriteDistance[0];
	i = 1;
	pos = 0;
	while (i < 3)
	{
		if (spriteDistance[i] > temp)
		{
			temp = spriteDistance[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int 	min_double(double *spriteDistance)
{
	int pos;
	int i;
	double temp;

	temp = spriteDistance[0];
	i = 1;
	pos = 0;
	while (i < 3)
	{
		if (spriteDistance[i] < temp)
		{
			temp = spriteDistance[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	sprite_casting(t_cub3d *cub3d, double *ZBuffer)
{
	double spriteDistance[numSprites];
	int spriteorder[numSprites];
	int i;
	int j;

	//sort sprites from far to close
	i = 0;
	while(i < numSprites)
	{
		spriteDistance[i] = ((cub3d->posx - cub3d->sprite[i].x) * (cub3d->posx - cub3d->sprite[i].x) + (cub3d->posy - cub3d->sprite[i].y) * (cub3d->posy - cub3d->sprite[i].y));
		i++;
	}
	j = 0;
	int temp = 4;
	while (j < 2)
	{
		i = 0;
		while (i < 2)
		{
			if(i == temp)
				i++;
			else
			{
				if (spriteDistance[i] > spriteDistance[i + 1])
					spriteorder[j] = i;
				else
					spriteorder[j] = i + 1;
				i++;
			}
		}
		temp = spriteorder[j];
		j++;
	}
	spriteorder[0] = max_double(spriteDistance);
	spriteorder[2] = min_double(spriteDistance);
	spriteorder[1] = 3 - spriteorder[0] - spriteorder[2];

	//after sorting the sprites, do the projection and draw them
	i = 0;
	
	while (i < numSprites)
	{
		if (cub3d->sprite[spriteorder[i]].flag == 0)
			i++;
		else
		{
			cub3d->flag2 = spriteorder[i];
			//translate sprite position to relative to camera
			double spriteX = cub3d->sprite[spriteorder[i]].x - cub3d->posx;
			double spriteY = cub3d->sprite[spriteorder[i]].y - cub3d->posy;

			double invDet = 1.0 / (cub3d->plane_x * cub3d->dir_y - cub3d->dir_x * cub3d->plane_y); //required for correct matrix multiplication

			double transformX = invDet * (cub3d->dir_y  * spriteX - cub3d->dir_x * spriteY);
			double transformY = invDet * (-cub3d->plane_y * spriteX + cub3d->plane_x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

			int spriteScreenX = (int)((WIDTH / 2) * (1 + transformX / transformY));

			//calculate height of the sprite on screen
			int spriteHeight = abs((int)(GHEIGHT / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
			
			//calculate lowest and highest pixel to fill in current stripe
			int drawStartY = -spriteHeight / 2 + GHEIGHT / 2;
/* 			if(drawStartY < 0)
				drawStartY = 0; */
			int drawEndY = spriteHeight / 2 + cub3d->viewport->height / 2;
/* 			if(drawEndY >= GHEIGHT)
				drawEndY = GHEIGHT - 1; */

			//calculate width of the sprite
			int spriteWidth = abs((int)(GHEIGHT / (transformY)));
			int drawStartX = -spriteWidth / 2 + spriteScreenX;
/* 			if(drawStartX < 0)
				drawStartX = 0; */
			int drawEndX = spriteWidth / 2 + spriteScreenX;
/* 			if(drawEndX >= WIDTH)
				drawEndX = WIDTH - 1; */

			//loop through every vertical stripe of the sprite on screen
			for (int stripe = drawStartX; stripe < drawEndX; stripe++)
			{
				if(transformY > 0 && stripe > 0 && stripe < WIDTH && transformY < ZBuffer[stripe])
				{
					int texx = ((((double)(stripe - drawStartX) / (drawEndX - drawStartX)) * cub3d->coll->width));
					int a = GHEIGHT / 2 - (drawEndY - drawStartY) / 2;
					int b = GHEIGHT / 2 + (drawEndY - drawStartY) / 2;
					int k = 0;
					while (a < b)
					{
						int color = calc_pix_color(k, key_frame_selector(cub3d), texx, (drawEndY - drawStartY) + 1);
						if (color != 0)
						{
							if (a >= GHEIGHT)
								a = GHEIGHT;
							else if (a <= 0)
								a = 0;
							set_pixel_img(cub3d->sprite_img, stripe, a, color);
						}
						a++;
						k++;
					}
				}
			}
			i++;
		}
	}
}

void	draw_game(t_cub3d *cub3d)
{
	cub3d->ray = 0;
	double ZBuffer[WIDTH];

	while (cub3d->ray < WIDTH)
	{
		raycaster_calculus(cub3d);
		wall_distance(cub3d);
		raycaster(cub3d);
		doorcaster(cub3d);
		//SET THE ZBUFFER FOR THE SPRITE CASTING
		ZBuffer[cub3d->ray] = cub3d->perp_wall_dist; //perpendicular distance is used
		cub3d->ray++;
	}
	sprite_casting(cub3d, ZBuffer);
}
