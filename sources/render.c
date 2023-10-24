/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:32 by jubernar          #+#    #+#             */
/*   Updated: 2023/01/06 15:55:35 by jubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(void *param)
{
	t_cub3d *cub3d = (t_cub3d*)param;
	
	if (cub3d->intro_bol == 0)
		mlx_image_to_window(cub3d->mlx, cub3d->I, 0, 0);
	else
	{
		draw_minimap_background(cub3d);
		draw_viewport(cub3d);
	}
}