#include "cub3d.h"

int	right_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return (1);
	else
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
		terminate("info map error");
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
		terminate("texture Wall error");
	ft_free_tab(info);
	return (0);
}

int	line_to_map(int y, char *line, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (right_map_char(line[i]) == 0)
			terminate("Map compromised");
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

int	copy_map(char *file, t_cub3d *cub3d)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("open failed");
	y = 0;
	while (y < 8)
	{
		line = get_next_line(fd);
		free(line);
		y++;
	}
	y = 0;
	while (y < cub3d->m_size_y)
	{
		line = get_next_line(fd);
		line = ft_strtrim(line, "\n");
		if (!line)
			terminate("parse alloc error");
		line_to_map(y, line, cub3d);
		free(line);
		y++;
	}
	cub3d->map[y] = 0;
	close(fd);
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
			y++;
		if ((int)ft_strlen(line) > x)
			x = ft_strlen(line);
		free(line);
	}
	close(fd);
	cub3d->m_size_x = x - 1;
	cub3d->m_size_y = y - 1;
	return (0);
}

int	read_info(char *file, t_cub3d *cub3d)
{
	int		fd;
	int		l;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("open failed");
	l = 0;
	while (l < 7) // fin th right condition to stop when needed before the map
	{
		line = get_next_line(fd);
		if (!line)
			terminate("parse alloc error");
		line = ft_strtrim(line, "\n");
		info_to_struct(line, cub3d);
		free(line);
		l++;
	}
	return (fd);
}

int	duplicate_map(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	cub3d->map_check = malloc((cub3d->m_size_y + 1 + 2) * sizeof(char *));
	while (y < cub3d->m_size_y + 2)
	{
		cub3d->map_check[y] = malloc((cub3d->m_size_x + 1 + 2) * sizeof(char));
		y++;
	}
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

void	floodfill(t_cub3d *cub3d, int y, int x, char new_val)
{
	if (x < 0 || x >= cub3d->m_size_x + 2 || y < 0 || y >= cub3d->m_size_y + 2)
		return ;
	if (cub3d->map_check[y][x] != '0')
		return; // Cell already visited or not part of the area
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
	int	y;
	int	fd;
	int	i;

	y = 0;
	if (ft_strnstr(file, ".cub", ft_strlen(file)) == 0)
		terminate("Wrong extension !");
	fd = read_info(file, cub3d);
	read_map_size(fd, cub3d);
	cub3d->map = malloc((cub3d->m_size_y + 1) * sizeof(char *));
	// protect and exit correctly
	while (y < cub3d->m_size_y)
	{
		cub3d->map[y] = malloc((cub3d->m_size_x + 1) * sizeof(char));
		// protect and exit correctly
		y++;
	}
	// find the right section for the map
	copy_map(file, cub3d);
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
