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

void	finding_door(t_cub3d *cub3d)
{
	if (cub3d->side == 'W' || cub3d->side == 'E')
		cub3d->door_perp_wall_dist = (cub3d->side_dist_x - cub3d->delta_dist_x);
	else
		cub3d->door_perp_wall_dist = (cub3d->side_dist_y - cub3d->delta_dist_y);
	cub3d->door_hit = 1;
	cub3d->door = &cub3d->map[cub3d->map_y][cub3d->map_x];
	cub3d->door_line_height = (int)(GHEIGHT / cub3d->door_perp_wall_dist
			* cub3d->wall_height * 1.15);
	if (cub3d->side == 'E' || cub3d->side == 'W')
		cub3d->door_wall_x = cub3d->posy + cub3d->door_perp_wall_dist
			* cub3d->raydir_y;
	else
		cub3d->door_wall_x = (cub3d->posx + cub3d->door_perp_wall_dist
				* cub3d->raydir_x) * 0.99999999;
	cub3d->door_wall_x -= floor((cub3d->door_wall_x));
}

void	finding_wall(t_cub3d *cub3d)
{
	while (cub3d->hit == 0)
	{
		if (cub3d->side_dist_x < cub3d->side_dist_y)
		{
			cub3d->side_dist_x += cub3d->delta_dist_x;
			cub3d->map_x += cub3d->step_x;
			if (cub3d->raydir_x < 0)
				cub3d->side = 'W';
			else
				cub3d->side = 'E';
		}
		else
		{
			cub3d->side_dist_y += cub3d->delta_dist_y;
			cub3d->map_y += cub3d->step_y;
			if (cub3d->raydir_y < 0)
				cub3d->side = 'N';
			else
				cub3d->side = 'S';
		}
		if (cub3d->map[cub3d->map_y][cub3d->map_x] == '1')
			cub3d->hit = 1;
		if (cub3d->map[cub3d->map_y][cub3d->map_x] == 'D')
			finding_door(cub3d);
	}
}

void	wall_distance(t_cub3d *cub3d)
{
	finding_wall(cub3d);
	if (cub3d->side == 'W' || cub3d->side == 'E')
		cub3d->perp_wall_dist = (cub3d->side_dist_x - cub3d->delta_dist_x);
	else
		cub3d->perp_wall_dist = (cub3d->side_dist_y - cub3d->delta_dist_y);
	cub3d->line_height = (int)(GHEIGHT / cub3d->perp_wall_dist
		* cub3d->wall_height * 1.15);
	if (cub3d->side == 'E' || cub3d->side == 'W')
		cub3d->wall_x = cub3d->posy + cub3d->perp_wall_dist * cub3d->raydir_y;
	else
		cub3d->wall_x = (cub3d->posx + cub3d->perp_wall_dist * cub3d->raydir_x)
			* 0.99999999;
	cub3d->wall_x -= floor((cub3d->wall_x));
}

mlx_image_t	*key_frame_selector(t_cub3d *cub3d)
{
	if (cub3d->key_frame / 3 == 1)
		return (cub3d->key1);
	if (cub3d->key_frame / 3 == 2)
		return (cub3d->key2);
	if (cub3d->key_frame / 3 == 3)
		return (cub3d->key3);
	if (cub3d->key_frame / 3 == 4)
		return (cub3d->key4);
	if (cub3d->key_frame / 3 == 5)
		return (cub3d->key5);
	if (cub3d->key_frame / 3 == 6)
		return (cub3d->key6);
	if (cub3d->key_frame / 3 == 7)
		return (cub3d->key7);
	if (cub3d->key_frame / 3 == 8)
		return (cub3d->key6);
	if (cub3d->key_frame / 3 == 9)
		return (cub3d->key5);
	if (cub3d->key_frame / 3 == 10)
		return (cub3d->key4);
	if (cub3d->key_frame / 3 == 11)
		return (cub3d->key3);
	if (cub3d->key_frame / 3 == 12)
		return (cub3d->key2);
	return (cub3d->key1);
}

void	doorcaster(t_cub3d *cub3d)
{
	int	texx;

	if (cub3d->door_hit == 1)
	{
		texx = cub3d->door_wall_x * cub3d->t_w->width;
		draw_door_line_textu(cub3d->door_line_height, texx, cub3d->t_e, cub3d);
	}
}

void	raycaster(t_cub3d *cub3d)
{
	int	texx;

	if (cub3d->side == 'N')
	{
		texx = cub3d->wall_x * cub3d->t_n->width;
		draw_line_textu(cub3d->line_height, texx, cub3d->t_n, cub3d);
	}
	else if (cub3d->side == 'S')
	{
		texx = cub3d->wall_x * cub3d->t_s->width;
		draw_line_textu(cub3d->line_height,
			cub3d->t_s->height - texx - 1, cub3d->t_s, cub3d);
	}
	else if (cub3d->side == 'E')
	{
		texx = cub3d->wall_x * cub3d->t_e->width;
		draw_line_textu(cub3d->line_height, texx, cub3d->t_e, cub3d);
	}
	else if (cub3d->side == 'W')
	{
		texx = cub3d->wall_x * cub3d->t_w->width;
		draw_line_textu(cub3d->line_height,
			cub3d->t_e->height - texx - 1, cub3d->t_w, cub3d);
	}
}
