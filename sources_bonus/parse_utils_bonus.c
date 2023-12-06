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

#include "cub3d_bonus.h"

int	right_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == 'c' || c == 'D' || c == 'Z')
		return (1);
	else
		return (0);
}

int	open_file_to_line(char *file, t_cub3d *cub3d)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("open failed", cub3d, 1, 0);
	i = 0;
	while (i++ < cub3d->map_line)
		free(get_next_line(fd));
	return (fd);
}

int	read_map_size(char *file, t_cub3d *cub3d, int fd)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open_file_to_line(file, cub3d);
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
	cub3d->m_size_x = x - 1;
	cub3d->m_size_y = y;
	return (close(fd));
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
		if (i == 0)
			map[i] = malloc((x) * sizeof(char));
		else if (i == y)
			map[i] = malloc((x) * sizeof(char));
		else if (i == y -1)
			map[i] = malloc((x) * sizeof(char));
		else if (i == y - 2)
			map[i] = malloc((x) * sizeof(char));
		else
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
