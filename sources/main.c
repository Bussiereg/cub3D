#include "cub3d.h"

int	cub3d_init(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WIDTH*2, HEIGHT, "SUBMOON", false);
	if (!cub3d->mlx)
		terminate("cub3d init error");

	cub3d->viewport = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx,cub3d->viewport, WIDTH, 0);
	if (!cub3d->viewport)
		terminate("cub3d init error");

	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx,cub3d->background, 0, 0);
	if (!cub3d->background)
		terminate("cub3d init error");

	cub3d->N = mlx_texture_to_image(cub3d->mlx, cub3d->text_N);
	cub3d->S = mlx_texture_to_image(cub3d->mlx, cub3d->text_S);
	cub3d->E = mlx_texture_to_image(cub3d->mlx, cub3d->text_E);
	cub3d->W = mlx_texture_to_image(cub3d->mlx, cub3d->text_W);

	cub3d->minimap = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx,cub3d->minimap, 0, 0);
	if (!cub3d->minimap)
		terminate("cub3d init error");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d		cub3d;

	if (argc != 2)
		terminate("Incorrect number of arguments!");
	cub3d.w_d_offset = 0;
	parse_map(argv[1], &cub3d);
	cub3d_init(&cub3d);

	//draw_background(&cub3d);
	draw_viewport(&cub3d);
	draw_minimap_background(&cub3d);
	mlx_key_hook(cub3d.mlx, &my_keyhook, &cub3d);
	//mlx_close_hook(cub3d.mlx, &win_close, &cub3d);
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (EXIT_SUCCESS);
}

int	to_draw_a_line(t_cub3d *cub3d)
{
	t_point a = {20, 20, 0x550055FF};
	t_point b = {200, 300, 0x550055FF};
	draw_line(a, b, cub3d->minimap);
	return (0);
}