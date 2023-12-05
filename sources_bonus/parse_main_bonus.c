/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:51 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	copy_map(char *file, t_cub3d *cub3d)
{
	int		y;
	int		fd;
	char	*line;

	fd = open_file_to_line(file, cub3d);
	y = 0;
	cub3d->map[cub3d->m_size_y] = 0;
	while (y < cub3d->m_size_y)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) > 0)
		{
			line = ft_strtrim(line, "\n");
			if (!line)
				terminate("parse alloc error", cub3d, 1, 1);
			line_to_map(y, line, cub3d);
		}
		y++;
		free(line);
	}
	close(fd);
	return (0);
}

void	floodfill(t_cub3d *cub3d, int y, int x, char new_val)
{
	if (x < 0 || x >= cub3d->m_size_x + 2 || y < 0 || y >= cub3d->m_size_y + 2)
		return ;
	if (cub3d->map_check[y][x] != '0' && cub3d->map_check[y][x] != 'c'
		&& cub3d->map_check[y][x] != 'D')
		return ;
	cub3d->map_check[y][x] = new_val;
	floodfill(cub3d, y - 1, x, new_val);
	floodfill(cub3d, y + 1, x, new_val);
	floodfill(cub3d, y, x + 1, new_val);
	floodfill(cub3d, y, x - 1, new_val);
}

int	check_wall(char **map, t_cub3d *cub3d)
{
	int	x;
	int	y;

	floodfill(cub3d, 0, 0, '.');
	if (cub3d->map_check[(int)(cub3d->posy) + 1][(int)(cub3d->posx) + 1] == '.')
		terminate("map not closed", cub3d, 1, 2);
	floodfill(cub3d, cub3d->posy + 1, cub3d->posx + 1, '.');
	y = -1;
	while (map[++y] != 0)
	{
		x = -1;
		while (map[y][++x] != 0)
		{
			if (map[y][x] == '0')
				terminate("map not closed inside", cub3d, 1, 2);
		}
	}
	return (0);
}

void	load_key_text(t_cub3d *cub3d)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("./texture/key-01.png");
	cub3d->key1 = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-02.png");
	cub3d->key2 = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-03.png");
	cub3d->key3 = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-04.png");
	cub3d->key4 = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-05.png");
	cub3d->key5 = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-06.png");
	cub3d->key6 = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./texture/key-07.png");
	cub3d->key7 = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
}

int	parse_map(char *file, t_cub3d *cub3d)
{
	if (ft_strnstr(file, ".cub", ft_strlen(file)) == 0)
		terminate("Wrong extension", cub3d, 1, 0);
	read_info(file, cub3d);
	read_map_size(file, cub3d, 0);
	cub3d->map = allocate_map(cub3d->m_size_y + 1, cub3d->m_size_x + 1);
	if (!cub3d->map)
		terminate("Map alloc fail", cub3d, 1, 0);
	copy_map(file, cub3d);
	cub3d->map_check = allocate_map(cub3d->m_size_y + 3, cub3d->m_size_x + 3);
	if (!cub3d->map_check)
		terminate("Map check alloc fail", cub3d, 1, 1);
	if (cub3d->posx == 0 || cub3d->posy == 0)
		terminate("no player position", cub3d, 1, 1);
	duplicate_map(cub3d);
	check_wall(cub3d->map_check, cub3d);
	load_key_text(cub3d);
	return (0);
}
