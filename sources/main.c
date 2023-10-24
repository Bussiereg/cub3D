#include "cub3d.h"

int	cub3d_init(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WIDTH * 2, HEIGHT, "SUBMOON", false);
	if (!cub3d->mlx)
		terminate("cub3d init error");

	cub3d->viewport = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx,cub3d->viewport, WIDTH, 0);
	if (!cub3d->viewport)
		terminate("cub3d init error");

	cub3d->minimap = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx,cub3d->minimap, 0, 0);
	if (!cub3d->minimap)
		terminate("cub3d init error");

	cub3d->intro = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx,cub3d->intro, WIDTH, 0);
	if (!cub3d->intro)
		terminate("cub3d init error");

	cub3d->text_I = mlx_load_png("./intro.png");
	cub3d->I = mlx_texture_to_image(cub3d->mlx, cub3d->text_I);
	cub3d->intro_bol = 0;

	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d		cub3d;

	if (argc != 2)
		terminate("Incorrect number of arguments!");
	cub3d_init(&cub3d);
	parse_map(argv[1], &cub3d);
	mlx_loop_hook(cub3d.mlx, &render, &cub3d);
	mlx_key_hook(cub3d.mlx, &my_keyhook, &cub3d);
	mlx_close_hook(cub3d.mlx, &win_close, &cub3d);
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (EXIT_SUCCESS);
}