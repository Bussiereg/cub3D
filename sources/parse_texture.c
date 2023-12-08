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

void	load_textures_2(mlx_texture_t *texture,
			mlx_image_t **text, t_cub3d *cub3d, char **info)
{
	texture = mlx_load_png(info[1]);
	if (!texture)
		terminate("texture loading error", cub3d, 1, 0);
	*text = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
}

void	load_textures(mlx_texture_t	*texture, t_cub3d *cub3d, char **info)
{
	if (ft_strncmp(info[0], "NO", 2) == 0)
		load_textures_2(texture, &cub3d->t_n, cub3d, info);
	if (ft_strncmp(info[0], "SO", 2) == 0)
		load_textures_2(texture, &cub3d->t_s, cub3d, info);
	if (ft_strncmp(info[0], "WE", 2) == 0)
		load_textures_2(texture, &cub3d->t_w, cub3d, info);
	if (ft_strncmp(info[0], "EA", 2) == 0)
		load_textures_2(texture, &cub3d->t_e, cub3d, info);
}

void	set_player_position(char map_char, int x, int y, t_cub3d *cub3d)
{
	cub3d->posx = x + 0.5;
	cub3d->posy = y + 0.5;
	cub3d->dir_x = (map_char == 'E') - (map_char == 'W');
	cub3d->dir_y = (map_char == 'S') - (map_char == 'N');
	cub3d->plane_x = (map_char == 'N') - (map_char == 'S');
	cub3d->plane_y = (map_char == 'E') - (map_char == 'W');
}
