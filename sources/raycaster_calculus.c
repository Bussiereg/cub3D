/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_calculus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:23:41 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:23:42 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	absol(double nombre)
{
	if (nombre < 0)
		return (-nombre);
	else
		return (nombre);
}

void	raycaster_init(t_cub3d *cub3d)
{
	cub3d->hit = 0;
	cub3d->lineHeight = 0;
	cub3d->cameraX = 2 * cub3d->ray / (double)WIDTH - 1;
	cub3d->rayDirX = cub3d->dirX + cub3d->planeX * cub3d->cameraX;
	cub3d->rayDirY = cub3d->dirY + cub3d->planeY * cub3d->cameraX;
	cub3d->mapX = (int)(cub3d->posX / UNIT);
	cub3d->mapY = (int)(cub3d->posY / UNIT);
	if (cub3d->rayDirX == 0)
		cub3d->deltaDistX = 2000000;
	else
		cub3d->deltaDistX = absol(1 / cub3d->rayDirX);
	if (cub3d->rayDirY == 0)
		cub3d->deltaDistY = 2000000;
	else
		cub3d->deltaDistY = absol(1 / cub3d->rayDirY);
}

void	raycaster_calculus(t_cub3d *cub3d)
{
	raycaster_init(cub3d);
	if (cub3d->rayDirX < 0)
	{
		cub3d->stepX = -1;
		cub3d->sideDistX = ((cub3d->posX) - cub3d->mapX) * cub3d->deltaDistX;
	}
	else
	{
		cub3d->stepX = 1;
		cub3d->sideDistX = (cub3d->mapX + 1 - (cub3d->posX))
			* cub3d->deltaDistX;
	}
	if (cub3d->rayDirY < 0)
	{
		cub3d->stepY = -1;
		cub3d->sideDistY = ((cub3d->posY) - cub3d->mapY)
			* cub3d->deltaDistY;
	}
	else
	{
		cub3d->stepY = 1;
		cub3d->sideDistY = (cub3d->mapY + 1 - (cub3d->posY))
			* cub3d->deltaDistY;
	}
}
