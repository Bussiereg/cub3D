#include "cub3d.h"

int	right_map_char(char c)
{
	if (c == '0' || c == '1' | c == ' ' || c == 'N' 
		|| c == 'S' || c == 'E' || c == 'W')
		return (0);
	else
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

int	parse_map(char *file, t_cub3d *cub3d)
{
	int y;

	y = 0;
	(void)file;

	if (ft_strnstr(file, ".cub", ft_strlen(file)) == 0)
		terminate("Wrong extension !");

	// Read the resolution
	//	?
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
