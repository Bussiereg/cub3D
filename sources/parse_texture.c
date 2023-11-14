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

int	get_color_info(char *str)
{
	char	**rgb;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	rgb = ft_split(str, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_tab(rgb);
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

void	set_player_position(char map_char, int x, int y, t_cub3d *cub3d)
{
	cub3d->pos_x = x * UNIT + UNIT / 2;
	cub3d->pos_y = y * UNIT + UNIT / 2;
	if (map_char == 'N')
		cub3d->pos_angle = 3 * M_PI / 2;
	else if (map_char == 'S')
		cub3d->pos_angle = M_PI / 2;
	else if (map_char == 'W')
		cub3d->pos_angle = 0;
	else if (map_char == 'E')
		cub3d->pos_angle = M_PI;
	cub3d->pos_dx = cos(cub3d->pos_angle);
	cub3d->pos_dy = sin(cub3d->pos_angle);
}
