/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:19:36 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:19:38 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	finding_wall(t_cub3d *cub3d)
{
	while (cub3d->hit == 0)
	{
		if (cub3d->sideDistX < cub3d->sideDistY)
		{
			cub3d->sideDistX += cub3d->deltaDistX;
			cub3d->mapX += cub3d->stepX;
			if (cub3d->rayDirX < 0)
				cub3d->side = 'W';
			else
				cub3d->side = 'E';
		}
		else
		{
			cub3d->sideDistY += cub3d->deltaDistY;
			cub3d->mapY += cub3d->stepY;
			if (cub3d->rayDirY < 0)
				cub3d->side = 'N';
			else
				cub3d->side = 'S';
		}
		if (cub3d->map[cub3d->mapY][cub3d->mapX] == '1') 
			cub3d->hit = 1;
	}
}

void	wall_distance(t_cub3d *cub3d)
{
	finding_wall(cub3d);
	if (cub3d->side == 'W' || cub3d->side == 'E')
		cub3d->perpWallDist = (cub3d->sideDistX - cub3d->deltaDistX);
	else
		cub3d->perpWallDist = (cub3d->sideDistY - cub3d->deltaDistY);
	cub3d->lineHeight = (int)(HEIGHT / cub3d->perpWallDist);
	if (cub3d->side == 'E' || cub3d->side == 'W' ) 
		cub3d->wallX = cub3d->posY + cub3d->perpWallDist * cub3d->rayDirY;
	else
		cub3d->wallX = (cub3d->posX + cub3d->perpWallDist * cub3d->rayDirX)*0.99999999;
	cub3d->wallX -= floor((cub3d->wallX));
}

void	raycaster(t_cub3d *cub3d)
{
	int	texx;
	texx = cub3d->wallX * cub3d->t_e->width;
	if (cub3d->side == 'N')
		draw_line_textu(cub3d->lineHeight, texx, cub3d->t_n, cub3d);
	else if (cub3d->side == 'S')
		draw_line_textu(cub3d->lineHeight,
			cub3d->t_s->height - texx - 1, cub3d->t_s, cub3d);
	else if (cub3d->side == 'E')
	{
		draw_line_textu(cub3d->lineHeight, texx, cub3d->t_e, cub3d);
	}
	else if (cub3d->side == 'W')
	{
		/* if (texx == 9)
		{

			printf("x = %d ", cub3d->ray);
			printf("text = 9 W\n");
		} */
		draw_line_textu(cub3d->lineHeight,
			cub3d->t_e->height - texx - 1, cub3d->t_w, cub3d);
	}
}