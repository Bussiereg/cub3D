/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:51 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	right_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	else
		return (0);
}

int	read_map_size(int fd, t_cub3d *cub3d)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	line = "line";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
		{
			if (ft_strlen(line) > 1)
				y++;
		}
		if ((int)ft_strlen(line) > x)
			x = ft_strlen(line);
		free(line);
	}
	close(fd);
	cub3d->m_size_x = x - 1;
	cub3d->m_size_y = y;
	return (0);
}

char	**allocate_map(int y, int x)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc((y) * sizeof(char *));
	if (!map)
		return (NULL);
	while (i < y)
	{
		map[i] = malloc((x) * sizeof(char));
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int	duplicate_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub3d->m_size_y + 2)
	{
		x = 0;
		while (x < cub3d->m_size_x + 2)
		{
			if (y == 0 || y == cub3d->m_size_y + 1)
				cub3d->map_check[y][x] = '0';
			else if (x == 0 || x == cub3d->m_size_x + 1)
				cub3d->map_check[y][x] = '0';
			else
				cub3d->map_check[y][x] = cub3d->map[y - 1][x - 1];
			x++;
		}
		cub3d->map_check[y][x] = 0;
		y++;
	}
	cub3d->map_check[y] = 0;
	return (0);
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
