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

#include "cub3d_bonus.h"

void	rotating_right(t_cub3d *cub3d)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = cub3d->dir_x;
	cub3d->dir_x = cub3d->dir_x * cos(ROTSPD) - cub3d->dir_y
		* sin(ROTSPD);
	cub3d->dir_y = old_dir_x * sin(ROTSPD) + cub3d->dir_y
		* cos(ROTSPD);
	old_plane_x = cub3d->plane_x;
	cub3d->plane_x = cub3d->plane_x * cos(ROTSPD) - cub3d->plane_y
		* sin(ROTSPD);
	cub3d->plane_y = old_plane_x * sin(ROTSPD) + cub3d->plane_y
		* cos(ROTSPD);
}

void	rotating_left(t_cub3d *cub3d)
{
	float	olddir_x;
	float	oldplane_x;

	olddir_x = cub3d->dir_x;
	cub3d->dir_x = cub3d->dir_x * cos(-ROTSPD) - cub3d->dir_y * sin(-ROTSPD);
	cub3d->dir_y = olddir_x * sin(-ROTSPD) + cub3d->dir_y * cos(-ROTSPD);
	oldplane_x = cub3d->plane_x;
	cub3d->plane_x = cub3d->plane_x * cos(-ROTSPD) - cub3d->plane_y
		* sin(-ROTSPD);
	cub3d->plane_y = oldplane_x * sin(-ROTSPD) + cub3d->plane_y * cos(-ROTSPD);
}

void	move_around(t_cub3d *cub3d)
{
	if (cub3d->move_up == 1)
		moving_up(cub3d);
	if (cub3d->move_down == 1)
		moving_down(cub3d);
	if (cub3d->move_left == 1)
		moving_left(cub3d);
	if (cub3d->move_right == 1)
		moving_right(cub3d);
	if (cub3d->rotate_right == 1)
		rotating_right(cub3d);
	if (cub3d->rotate_left == 1)
		rotating_left(cub3d);
}
