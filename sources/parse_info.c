/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:51 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	line_to_map(int y, char *line, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (right_map_char(line[i]) == 0)
			terminate("Map compromised", cub3d, 1);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
		{
			cub3d->pos_x = i * UNIT + UNIT / 2;
			cub3d->pos_y = y * UNIT + UNIT / 2;
			if (line[i] == 'N')
				cub3d->pos_angle = 3 * M_PI / 2;
			if (line[i] == 'S')
				cub3d->pos_angle = M_PI / 2;
			if (line[i] == 'W')
				cub3d->pos_angle = 0;
			if (line[i] == 'E')
				cub3d->pos_angle = M_PI;
			cub3d->pos_dx = cos(cub3d->pos_angle);
			cub3d->pos_dy = sin(cub3d->pos_angle);
			line[i] = '0';
		}
		if (line[i] == ' ')
			cub3d->map[y][i] = '0';
		else
			cub3d->map[y][i] = line[i];
		i++;
	}
	while (i < cub3d->m_size_x)
	{
		cub3d->map[y][i] = '0';
		i++;
	}
	cub3d->map[y][i] = 0;
	return (0);
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

int	info_to_struct(char *line, t_cub3d *cub3d)
{
	char	**info;

	if (line[0] == 0)
		return (0);
	info = ft_split(line, ' ');
	if (info[2] != 0)
		terminate("info map error", cub3d, 1);
	if (ft_strncmp(info[0], "F", 2) == 0)
		cub3d->color_F = get_color_info(info[1]);
	if (ft_strncmp(info[0], "C", 2) == 0)
		cub3d->color_C = get_color_info(info[1]);
	if (ft_strncmp(info[0], "NO", 2) == 0)
		cub3d->N = mlx_texture_to_image(cub3d->mlx, mlx_load_png(info[1]));
	if (ft_strncmp(info[0], "SO", 2) == 0)
		cub3d->S = mlx_texture_to_image(cub3d->mlx, mlx_load_png(info[1]));
	if (ft_strncmp(info[0], "WE", 2) == 0)
		cub3d->W = mlx_texture_to_image(cub3d->mlx, mlx_load_png(info[1]));
	if (ft_strncmp(info[0], "EA", 2) == 0)
		cub3d->E = mlx_texture_to_image(cub3d->mlx, mlx_load_png(info[1]));
	if (!cub3d->N || !cub3d->S || !cub3d->E || !cub3d->W)
		terminate("texture Wall error", cub3d, 1);
	ft_free_tab(info);
	return (0);
}

int	all_info_read(t_cub3d *cub3d)
{
	if (cub3d->N == cub3d->viewport || cub3d->S == cub3d->viewport
		|| cub3d->E == cub3d->viewport || cub3d->W == cub3d->viewport
		|| cub3d->color_C == 0 || cub3d->color_F == 0)
		return (0);
	return (1);
}

int	read_info(char *file, t_cub3d *cub3d)
{
	int		fd;
	int		l;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("open failed", cub3d, 1);
	l = 0;
	while (all_info_read(cub3d) == 0)
	{
		line = get_next_line(fd);
		if (!line)
			terminate("parse alloc error", cub3d, 1);
		line = ft_strtrim(line, "\n");
		info_to_struct(line, cub3d);
		free(line);
		l++;
		cub3d->map_line = l;
	}
	return (fd);
}
