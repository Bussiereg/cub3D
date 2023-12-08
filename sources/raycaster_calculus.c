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
	cub3d->line_height = 0;
	cub3d->camera_x = 2 * cub3d->ray / (double)WIDTH - 1;
	cub3d->raydir_x = cub3d->dir_x + cub3d->plane_x * cub3d->camera_x;
	cub3d->raydir_y = cub3d->dir_y + cub3d->plane_y * cub3d->camera_x;
	cub3d->map_x = (int)(cub3d->posx);
	cub3d->map_y = (int)(cub3d->posy);
	if (cub3d->raydir_x == 0)
		cub3d->delta_dist_x = 2000000;
	else
		cub3d->delta_dist_x = absol(1 / cub3d->raydir_x);
	if (cub3d->raydir_y == 0)
		cub3d->delta_dist_y = 2000000;
	else
		cub3d->delta_dist_y = absol(1 / cub3d->raydir_y);
}

void	raycaster_calculus(t_cub3d *cub3d)
{
	raycaster_init(cub3d);
	if (cub3d->raydir_x < 0)
	{
		cub3d->step_x = -1;
		cub3d->side_dist_x = ((cub3d->posx) - cub3d->map_x)
			* cub3d->delta_dist_x;
	}
	else
	{
		cub3d->step_x = 1;
		cub3d->side_dist_x = (cub3d->map_x + 1 - (cub3d->posx))
			* cub3d->delta_dist_x;
	}
	if (cub3d->raydir_y < 0)
	{
		cub3d->step_y = -1;
		cub3d->side_dist_y = ((cub3d->posy) - cub3d->map_y)
			* cub3d->delta_dist_y;
	}
	else
	{
		cub3d->step_y = 1;
		cub3d->side_dist_y = (cub3d->map_y + 1 - (cub3d->posy))
			* cub3d->delta_dist_y;
	}
}
