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
	cub3d->pos_angle += ROTATE;
	cub3d->pos_angle = fix_angle(cub3d->pos_angle);
	cub3d->pos_dx = cos(cub3d->pos_angle);
	cub3d->pos_dy = sin(cub3d->pos_angle);
}

void	rotating_left(t_cub3d *cub3d)
{
	cub3d->pos_angle -= ROTATE;
	cub3d->pos_angle = fix_angle(cub3d->pos_angle);
	cub3d->pos_dx = cos(cub3d->pos_angle);
	cub3d->pos_dy = sin(cub3d->pos_angle);
}
