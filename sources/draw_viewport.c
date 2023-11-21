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

double absol(double nombre) {
    if (nombre < 0)
	{
        return (-nombre);
    } 
	else 
	{
        return (nombre);
    }
}

void	draw_game(t_cub3d *cub3d)
{
	int stepX;
	int stepY;
	double	perpWallDist;
	int	hit;
	char side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	
	cub3d->ray = 0;
	while (cub3d->ray < WIDTH)
	{
		hit = 0;
		lineHeight = 0;
		cub3d->cameraX = 2 * cub3d->ray / (double)WIDTH - 1;
		cub3d->rayDirX = cub3d->dirX + cub3d->planeX * cub3d->cameraX;
		cub3d->rayDirY = cub3d->dirY + cub3d->planeY * cub3d->cameraX;
		cub3d->mapX = (int)(cub3d->posX / UNIT);
		cub3d->mapY = (int)(cub3d->posY / UNIT);
		if (cub3d->rayDirX == 0)
			cub3d->deltaDistX = 2000000;
		else
			cub3d->deltaDistX= absol(1 / cub3d->rayDirX);
		if (cub3d->rayDirY == 0)
			cub3d->deltaDistY = 2000000;
		else
			cub3d->deltaDistY= absol(1 / cub3d->rayDirY);
		if (cub3d->rayDirX < 0)
		{
			stepX = -1;
			cub3d->sideDistX = ((cub3d->posX / UNIT) - cub3d->mapX) * cub3d->deltaDistX;
		}
		else
		{
			stepX = 1;
			cub3d->sideDistX = (cub3d->mapX + 1 - (cub3d->posX / UNIT)) * cub3d->deltaDistX;
		}
		if (cub3d->rayDirY < 0)
		{
			stepY = -1;
			cub3d->sideDistY = ((cub3d->posY / UNIT) - cub3d->mapY) * cub3d->deltaDistY;
		}
		else
		{
			stepY = 1;
			cub3d->sideDistY = (cub3d->mapY + 1 - (cub3d->posY / UNIT)) * cub3d->deltaDistY;
		}
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (cub3d->sideDistX < cub3d->sideDistY)
			{
				cub3d->sideDistX += cub3d->deltaDistX;
				cub3d->mapX += stepX;
				if (cub3d->rayDirX < 0)
					side = 'W';
				else
					side = 'E';
			}
			else
			{
				cub3d->sideDistY += cub3d->deltaDistY;
				cub3d->mapY += stepY;
				if (cub3d->rayDirY < 0)
					side = 'N';
				else
					side = 'S';
			}
			if (cub3d->map[cub3d->mapY][cub3d->mapX] == '1') 
				hit = 1;
		}
		// printf("mapX: %d mapY: %d ", cub3d->mapX, cub3d->mapY);
		if(side == 'W' || side == 'E') 
			perpWallDist = (cub3d->sideDistX - cub3d->deltaDistX);
		else
			perpWallDist = (cub3d->sideDistY - cub3d->deltaDistY);
		// printf("sideDistX: %f sideDistY: %f deltaDistX: %f deltaDistY: %f", cub3d->sideDistX, cub3d->sideDistY, cub3d->deltaDistX, cub3d->deltaDistY);
		// printf("perpWalldist: %f ", perpWallDist);
		lineHeight = (int)(HEIGHT / perpWallDist);
		// printf("lineHeight: %d ", lineHeight);
		// printf("drawStart: %d drawEnd: %d ", drawStart, drawEnd);
		drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		while (drawStart < drawEnd)
		{
			if (side == 'N')
				mlx_put_pixel(cub3d->viewport, cub3d->ray, drawStart, 0x0000FFFF);
			else if (side == 'S')
				mlx_put_pixel(cub3d->viewport, cub3d->ray, drawStart, 0xFFFFFFFF);
			else if (side == 'E')
				mlx_put_pixel(cub3d->viewport, cub3d->ray, drawStart, 0xFF0000FF);
			else if (side == 'W')
				mlx_put_pixel(cub3d->viewport, cub3d->ray, drawStart, 0x00FF00FF);
			drawStart++;
		}
		// raycaster(cub3d, ray_angle);
		cub3d->ray++;
	}
}
