#include "cub3d.h"

int	cub3d_init(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "SUBMOON", false);
	if (!cub3d->mlx)
		return (1);
	cub3d->viewport = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx,cub3d->viewport, 0, 0);
	if (!cub3d->viewport)
		return (1);
	cub3d->minimap = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx,cub3d->minimap, 0, 0);
	if (!cub3d->minimap)
		return (1);
	cub3d->intro_bol = 0;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d		cub3d;

	if (argc != 2)
		terminate("Incorrect number of arguments!");
	if (cub3d_init(&cub3d) == 1)
		terminate("Init cub3d  mlx42 error");
	parse_map(argv[1], &cub3d);
//	render(&cub3d);
	mlx_loop_hook(cub3d.mlx, &render, &cub3d); //For every frame rendering
	mlx_key_hook(cub3d.mlx, &my_keyhook, &cub3d);
	mlx_close_hook(cub3d.mlx, &win_close, &cub3d);
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (EXIT_SUCCESS);
}