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

#include "cub3d_bonus.h"

void	load_key_text_1(t_cub3d *cub3d)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./texture/key-01.png");
	if (!texture)
		terminate("key texture file missing", cub3d, 1, 2);
	cub3d->key1 = mlx_texture_to_image(cub3d->mlx, texture);
	if (!cub3d->key1)
		terminate("key texture memory fail", cub3d, 1, 2);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-02.png");
	if (!texture)
		terminate("key texture file missing", cub3d, 1, 2);
	cub3d->key2 = mlx_texture_to_image(cub3d->mlx, texture);
	if (!cub3d->key2)
		terminate("key texture memory fail", cub3d, 1, 2);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-03.png");
	if (!texture)
		terminate("key texture file missing", cub3d, 1, 2);
	cub3d->key3 = mlx_texture_to_image(cub3d->mlx, texture);
	if (!cub3d->key3)
		terminate("key texture memory fail", cub3d, 1, 2);
	mlx_delete_texture(texture);
}

void	load_key_text_2(t_cub3d *cub3d)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./texture/key-04.png");
	if (!texture)
		terminate("key texture file missing", cub3d, 1, 2);
	cub3d->key4 = mlx_texture_to_image(cub3d->mlx, texture);
	if (!cub3d->key4)
		terminate("key texture memory fail", cub3d, 1, 2);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-05.png");
	if (!texture)
		terminate("key texture file missing", cub3d, 1, 2);
	cub3d->key5 = mlx_texture_to_image(cub3d->mlx, texture);
	if (!cub3d->key5)
		terminate("key texture memory fail", cub3d, 1, 2);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-06.png");
	if (!texture)
		terminate("key texture file missing", cub3d, 1, 2);
	cub3d->key6 = mlx_texture_to_image(cub3d->mlx, texture);
	if (!cub3d->key6)
		terminate("key texture memory fail", cub3d, 1, 2);
	mlx_delete_texture(texture);
}

void	load_key_text_3(t_cub3d *cub3d)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./texture/key-07.png");
	if (!texture)
		terminate("key texture file missing", cub3d, 1, 2);
	cub3d->key7 = mlx_texture_to_image(cub3d->mlx, texture);
	if (!cub3d->key7)
		terminate("key texture memory fail", cub3d, 1, 2);
	mlx_delete_texture(texture);
}

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

void	set_player_position(char map_char, int x, int y, t_cub3d *cub3d)
{
	cub3d->posx = x + 0.5;
	cub3d->posy = y + 0.5;
	cub3d->dir_x = (map_char == 'E') - (map_char == 'W');
	cub3d->dir_y = (map_char == 'S') - (map_char == 'N');
	cub3d->plane_x = (map_char == 'N') - (map_char == 'S');
	cub3d->plane_y = (map_char == 'E') - (map_char == 'W');
}
