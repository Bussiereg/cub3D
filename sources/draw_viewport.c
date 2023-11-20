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
	int stepX;
	int stepY;
	double	perpWallDist;
	int	hit = 0;
	int side;
	int lineHeight = 0;
	
	cub3d->ray = 0;
	// cub3d->vx = cub3d->posX;
	// cub3d->vy = cub3d->posY;
	// cub3d->hx = cub3d->posX;
	// cub3d->hy = cub3d->posY;
	cub3d->xo = 0;
	cub3d->yo = 0;
	while (cub3d->ray <= WIDTH)
	{
		cub3d->cameraX = 2 * cub3d->ray / (double)WIDTH - 1;
		cub3d->rayDirX = cub3d->dirX + cub3d->planeX * cub3d->cameraX;
		cub3d->rayDirY = cub3d->dirY + cub3d->planeY * cub3d->cameraX;
		cub3d->mapX = (int)cub3d->posX;
		cub3d->mapY = (int)cub3d->posY;
		if (cub3d->dirX == 0)
			cub3d->deltaDistX = = 1000000;
		else
			cub3d->deltaDistX= sqrt(1 + (cub3d->rayDirY * cub3d->rayDirY) / (cub3d->rayDirX * cub3d->rayDirX));
		if (cub3d->dirY == 0)
			cub3d->deltaDistY = = 1000000;
		else
			cub3d->deltaDistY= sqrt(1 + (cub3d->rayDirX * cub3d->rayDirX) / (cub3d->rayDirY * cub3d->rayDirY));
     if (cubd3d->rayDirX < 0)
      {
        stepX = -1;
        cubd3d->sideDistX = (cubd3d->posX - cubd3d->mapX) * cubd3d->deltaDistX;
      }
      else
      {
        stepX = 1;
        cubd3d->sideDistX = (cubd3d->mapX + 1 - cubd3d->posX) * cubd3d->deltaDistX;
      }
      if (cubd3d->rayDirY < 0)
      {
        stepY = -1;
        cubd3d->sideDistY = (cubd3d->posY - cubd3d->mapY) * cubd3d->deltaDistY;
      }
      else
      {
        stepY = 1;
        cubd3d->sideDistY = (cubd3d->mapY + 1 - cubd3d->posY) * cubd3d->deltaDistY;
      }
     while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (cubd3d->sideDistX < cubd3d->sideDistY)
        {
          cubd3d->sideDistX += cubd3d->deltaDistX;
          cubd3d->mapX += stepX;
          side = 0;
        }
        else
        {
          cubd3d->sideDistY += cubd3d->deltaDistY;
          cubd3d->mapY += stepY;
          side = 1;
        }
        if (cub3d->map[cubd3d->mapX][cubd3d->mapY] == '1') 
			hit = 1;
      }
		if(side == 0) 
			perpWallDist = (cub3d->sideDistX - cub3d->deltaDistX);
		else
        	perpWallDist = (cub3d->sideDistY - cub3d->deltaDistY);
		// check_horizontal_line(cub3d, ray_angle, 0);
		// check_vertical_line(cub3d, ray_angle, 0);
		// calculate_wall_distance(cub3d);
		// raycaster(cub3d, ray_angle);
		cub3d->ray++;
	}
}
