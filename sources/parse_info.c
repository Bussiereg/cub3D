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
	while (line[i])
	{
		if (right_map_char(line[i]) == 0)
			terminate("Map compromised", cub3d, 1, 1);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
		{
			set_player_position(line[i], i, y, cub3d);
			line[i] = '0';
		}
		if (line[i] == ' ')
			cub3d->map[y][i] = '0';
		else
			cub3d->map[y][i] = line[i];
		i++;
	}
	while (i < cub3d->m_size_x)
		cub3d->map[y][i++] = '0';
	cub3d->map[y][i] = 0;
	return (0);
}

int	info_to_struct(char *line, t_cub3d *cub3d)
{
	char	**info;

	if (line[0] == 0)
		return (0);
	info = ft_split(line, ' ');
	if (info[1] == 0)
	{
		ft_free_tab(info);
		return (0);
	}
	if (info[2] != 0)
		terminate("info map error", cub3d, 1, 0);
	if (ft_strncmp(info[0], "F", 2) == 0)
		cub3d->color_f = get_color_info(info[1]);
	if (ft_strncmp(info[0], "C", 2) == 0)
		cub3d->color_c = get_color_info(info[1]);
	load_textures(NULL, cub3d, info);
	if (!cub3d->t_n || !cub3d->t_s || !cub3d->t_e || !cub3d->t_w)
		terminate("texture Wall error", cub3d, 1, 0);
	ft_free_tab(info);
	return (0);
}

int	all_info_read(t_cub3d *cub3d)
{
	if (cub3d->t_n == cub3d->viewport || cub3d->t_s == cub3d->viewport
		|| cub3d->t_e == cub3d->viewport || cub3d->t_w == cub3d->viewport
		|| cub3d->color_c == 0 || cub3d->color_f == 0)
		return (0);
	return (1);
}

int	map_line(char *line)
{
	int	i;
	int	y;
	int	n;

	i = 0;
	y = 0;
	n = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
			y = 1;
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
			n = 1;
		i++;
	}
	if (y == 1 && n == 0)
		return (1);
	return (0);
}

int	read_info(char *file, t_cub3d *cub3d)
{
	int		fd;
	int		l;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("open failed", cub3d, 1, 0);
	l = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			terminate("info map error", cub3d, 1, 0);
		line = ft_strtrim(line, "\n");
		info_to_struct(line, cub3d);
		if (all_info_read(cub3d) == 1 && map_line(line) == 1)
		{
			free(line);
			break ;
		}
		free(line);
		cub3d->map_line = ++l;
	}
	close(fd);
	return (0);
}
