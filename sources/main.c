#include "cub3d.h"

int	parse_map(char *file_name, t_cub3d *cub3d)
{
	int y;

	y = 0;
	(void)file_name;

	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == 0)
		terminate("Wrong extension !");

	// Read the resolution

	// read the texture info
	
	// read and store the RGB color infos

	// find out the size of the map 

	cub3d->m_size_x = 33;
	cub3d->m_size_y = 14;

	// allocate map
	
	cub3d->map = malloc(cub3d->m_size_y * sizeof(int *));
	// protect and exit correctly

	while (y < cub3d->m_size_y)
	{
		cub3d->map[y] = malloc(cub3d->m_size_x * sizeof(int));
		// protect and exit correctly
		y++;
	}

}

int	cub3d_init(t_cub3d *cub3d)
{
	

	cub3d->mlx = mlx_init(1920, 1080, "cub3D", false);
	if (!cub3d->mlx)
		terminate("cub3d init error");

	cub3d->viewport = mlx_new_image(cub3d->mlx, 1920, 1080);
	if (!cub3d->viewport)
		terminate("cub3d init error");

	// Parse map to get the size of the minimap or always the same size?

	cub3d->minimap = mlx_new_image(cub3d->mlx, 400, 400);
	if (!cub3d->minimap)
		terminate("cub3d init error");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d		cub3d;

	if (argc != 2)
		terminate("Incorrect number of arguments !");


	parse_map(argv[1], &cub3d);
		//if map problem stop here
	cub3d_init(&cub3d);
		//if init problem stop here


	draw_minimap(&cub3d);
	/* mlx_key_hook(fdf->mlx, &my_keyhook, fdf);
	mlx_close_hook(fdf->mlx, &win_close, fdf); */
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (EXIT_SUCCESS);
}
