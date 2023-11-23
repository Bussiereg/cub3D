/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:45:20 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/09 12:45:22 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotating_right(t_cub3d *cub3d)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = cub3d->dirX;
	cub3d->dirX = cub3d->dirX * cos(ROTSPEED) - cub3d->dirY * sin(ROTSPEED);
	cub3d->dirY = old_dir_x * sin(ROTSPEED) + cub3d->dirY * cos(ROTSPEED);
	old_plane_x = cub3d->planeX;
	cub3d->planeX = cub3d->planeX * cos(ROTSPEED) - cub3d->planeY * sin(ROTSPEED);
	cub3d->planeY = old_plane_x * sin(ROTSPEED) + cub3d->planeY * cos(ROTSPEED);
}

void	rotating_left(t_cub3d *cub3d)
{
	float oldDirX;
	float oldPlaneX;

	oldDirX = cub3d->dirX;
	cub3d->dirX = cub3d->dirX * cos(-ROTSPEED) - cub3d->dirY * sin(-ROTSPEED);
	cub3d->dirY = oldDirX * sin(-ROTSPEED) + cub3d->dirY * cos(-ROTSPEED);
	oldPlaneX = cub3d->planeX;
	cub3d->planeX = cub3d->planeX * cos(-ROTSPEED) - cub3d->planeY * sin(-ROTSPEED);
	cub3d->planeY = oldPlaneX * sin(-ROTSPEED) + cub3d->planeY * cos(-ROTSPEED);
}
