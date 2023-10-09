#include "cub3d.h"

int	cub3d_init(t_cub3d *cub3d)
{
	

	cub3d->mlx = mlx_init(2000, 1000, "cub3D", false);
	if (!cub3d->mlx)
		terminate("cub3d init error");

	cub3d->viewport = mlx_new_image(cub3d->mlx, 2000, 1000);
	if (!cub3d->viewport)
		terminate("cub3d init error");

	// Parse map to get the size of the minimap or always the same size?

	cub3d->minimap = mlx_new_image(cub3d->mlx, 1000, 1000);
	if (!cub3d->minimap)
		terminate("cub3d init error");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d		cub3d;

	if (argc != 2)
		terminate("Incorrect number of arguments!");

	parse_map(argv[1], &cub3d);
		//if map problem stop here
	cub3d_init(&cub3d);
		//if init problem stop here

/* 	int i = 0;
	while (cub3d.map[i] != 0)
	{
		printf("%s\n", cub3d.map[i]);
		i++;
	} */

	draw_minimap_background(&cub3d);
	/* mlx_key_hook(fdf->mlx, &my_keyhook, fdf);
	mlx_close_hook(fdf->mlx, &win_close, fdf); */
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (EXIT_SUCCESS);
}
