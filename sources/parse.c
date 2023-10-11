#include "cub3d.h"

int	right_map_char(char c)
{
	if (c == '0' || c == '1' | c == ' ' || c == 'N' 
		|| c == 'S' || c == 'E' || c == 'W')
		return (0);
	else
		return (0);
}

int	get_color_info(char *s)
{
	(void)s;
	return (0);
}

int	get_texture_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("texture file opening problem");
	return (fd);
}

int	info_to_struct(char *line, t_cub3d *cub3d)
{
	char **info;

	if (line[0] == 0)
		return (0);
	
	//printf("%s\n", line);
	info = ft_split(line, ' ');
	if (info[2] != 0)
		terminate("*info map error");

	if (ft_strncmp(info[0], "F", 2) == 0)
		cub3d->color_F = get_color_info(info[1]);
	if (ft_strncmp(info[0], "C", 2) == 0)
		cub3d->color_C = get_color_info(info[1]);

	printf("%s\n", info[1]);
	int	fd;

	fd = open(info[1], O_RDONLY);
	if (fd < 0)
		terminate("texture file opening problem");
	if (ft_strncmp(info[0], "NO", 2) == 0)
		cub3d->text_N = mlx_load_png(info[1]);	
	if (!cub3d->text_N)
			terminate("texture N error");


	if (ft_strncmp(info[0], "SO", 2) == 0)
		cub3d->text_S = mlx_load_png(info[1]);
	if (!cub3d->text_S)
			terminate("texture S error");
	if (ft_strncmp(info[0], "WE", 2) == 0)
		cub3d->text_W = mlx_load_png(info[1]);
	if (!cub3d->text_W)
			terminate("texture W error");
	if (ft_strncmp(info[0], "EA", 2) == 0)
		cub3d->text_E = mlx_load_png(info[1]);
	if (!cub3d->text_E)
			terminate("texture E error");
		
	ft_free_tab(info);
	return (0);
}

int	line_to_map(int y, char *line, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
	/* 	if (right_map_char(line[i]) == 0)
			terminate("Map compromised"); */
			// free alloc;
		if (line[i] == ' ')
			cub3d->map[y][i] = '.';
		else
			cub3d->map[y][i] = line[i];
		i++;
	}
	cub3d->map[y][i] = 0;
	return (0);
}

int	copy_map(char *file, t_cub3d *cub3d)
{
	int	fd;
	int	y;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("open failed");

	y = 0;
	while (y < cub3d->m_size_y)
	{	
		line = get_next_line(fd);
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

int	read_info(char *file, t_cub3d *cub3d)
{
	int	fd;
	int	l;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate("open failed");

	l = 0;
	while (l < 8)
	{	
		line = get_next_line(fd);
		if (!line)
			terminate("parse alloc error");
		info_to_struct(line, cub3d);
		free(line);
		l++;
	}
	close(fd);
	return (0);
}

int	parse_map(char *file, t_cub3d *cub3d)
{
	int y;

	y = 0;

	if (ft_strnstr(file, ".cub", ft_strlen(file)) == 0)
		terminate("Wrong extension !");

	read_info(file, cub3d);
	// read the texture info
	//	?
	// read and store the RGB color infos
	//	?


	// find out the size of the map 
	//	?
	cub3d->m_size_x = 33;
	cub3d->m_size_y = 14;

	// allocate map
	
	cub3d->map = malloc((cub3d->m_size_y + 1) * sizeof(char *));
	// protect and exit correctly

	while (y < cub3d->m_size_y)
	{
		cub3d->map[y] = malloc((cub3d->m_size_x + 1) * sizeof(char));
		// protect and exit correctly
		y++;
	}

	copy_map(file, cub3d);

	return (0);
}
