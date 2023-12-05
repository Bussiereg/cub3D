/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:51 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mousehook(mouse_key_t button, action_t action, modifier_key_t mods,
	void *param)
{
	t_cub3d	*cub3d;
	int		x;
	int		y;

	(void)mods;
	cub3d = (t_cub3d *)param;
	mlx_get_mouse_pos(cub3d->mlx, &x, &y);
	if ((button == MLX_MOUSE_BUTTON_LEFT)
		&& action == MLX_PRESS)
	{
		if (x < WIDTH / 2)
			cub3d->rotate_left = 1;
		else
			cub3d->rotate_right = 1;
	}
	if ((button == MLX_MOUSE_BUTTON_LEFT)
		&& action == MLX_RELEASE)
	{
		if (cub3d->rotate_left == 1)
			cub3d->rotate_left = 0;
		if (cub3d->rotate_right == 1)
			cub3d->rotate_right = 0;
	}
}
