/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:51 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(mlx_texture_t	*texture, t_cub3d *cub3d, char **info)
{
	if (ft_strncmp(info[0], "NO", 2) == 0)
	{
		texture = mlx_load_png(info[1]);
		cub3d->t_n = mlx_texture_to_image(cub3d->mlx, texture);
		mlx_delete_texture(texture);
	}
	if (ft_strncmp(info[0], "SO", 2) == 0)
	{
		texture = mlx_load_png(info[1]);
		cub3d->t_s = mlx_texture_to_image(cub3d->mlx, texture);
		mlx_delete_texture(texture);
	}
	if (ft_strncmp(info[0], "WE", 2) == 0)
	{
		texture = mlx_load_png(info[1]);
		cub3d->t_w = mlx_texture_to_image(cub3d->mlx, texture);
		mlx_delete_texture(texture);
	}
	if (ft_strncmp(info[0], "EA", 2) == 0)
	{
		texture = mlx_load_png(info[1]);
		cub3d->t_e = mlx_texture_to_image(cub3d->mlx, texture);
		mlx_delete_texture(texture);
	}
}
