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

#include "cub3d.h"

int	copy_map(char *file, t_cub3d *cub3d, int fd)
{
	int		y;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("open failed", cub3d, 1);
	while (0 < cub3d->map_line--)
		free(get_next_line(fd));
	y = 0;
	while (y < cub3d->m_size_y)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) > 1)
		{
			line = ft_strtrim(line, "\n");
			if (!line)
				terminate("parse alloc error", cub3d, 1);
			line_to_map(y, line, cub3d);
			y++;
		}
		free(line);
	}
	cub3d->map[y] = 0;
	close(fd);
	return (0);
}

void	floodfill(t_cub3d *cub3d, int y, int x, char new_val)
{
	if (x < 0 || x >= cub3d->m_size_x + 2 || y < 0 || y >= cub3d->m_size_y + 2)
		return ;
	if (cub3d->map_check[y][x] != '0')
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
	if (cub3d->map_check[(int)(cub3d->pos_y / UNIT) + 1][(int)(cub3d->pos_x
			/ UNIT) + 1] == '.')
		printf("map not closed\n");
	floodfill(cub3d, cub3d->pos_y / UNIT + 1, cub3d->pos_x / UNIT + 1, '.');
	y = -1;
	while (map[++y] != 0)
	{
		x = -1;
		while (map[y][++x] != 0)
		{
			if (map[y][x] == '0')
				printf("map not closed inside\n");
		}
	}
	return (0);
}

int	parse_map(char *file, t_cub3d *cub3d)
{
	int	fd;
	int	i;

	if (ft_strnstr(file, ".cub", ft_strlen(file)) == 0)
		terminate("Wrong extension", cub3d, 1);
	fd = read_info(file, cub3d);
	read_map_size(fd, cub3d);
	cub3d->map = allocate_map(cub3d->m_size_y + 1, cub3d->m_size_x + 1);
	if (!cub3d->map)
		terminate("Map alloc fail", cub3d, 1);
	copy_map(file, cub3d, 0);
	cub3d->map_check = allocate_map(cub3d->m_size_y + 3, cub3d->m_size_x + 3);
	if (!cub3d->map_check)
		terminate("Map check alloc fail", cub3d, 1);
	duplicate_map(cub3d);
	check_wall(cub3d->map_check, cub3d);
	i = 0;
	while (cub3d->map_check[i] != 0)
	{
		printf("%s\n", cub3d->map_check[i]);
		i++;
	}
	return (0);
}
