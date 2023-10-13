#include "cub3d.h"

int	cub3d_init(t_cub3d *cub3d)
{

	cub3d->mlx = mlx_init(1800, 900, "SUBMOON", false);
	if (!cub3d->mlx)
		terminate("cub3d init error");

	cub3d->viewport = mlx_new_image(cub3d->mlx, 900, 900);
	mlx_image_to_window(cub3d->mlx,cub3d->viewport, 900, 0);
	if (!cub3d->viewport)
		terminate("cub3d init error");

	// Parse map to get the size of the minimap or always the same size?

	cub3d->minimap = mlx_new_image(cub3d->mlx, 900, 900);
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

	parse_map(argv[1], &cub3d);
	cub3d_init(&cub3d);

	cub3d.pos_x = 16 * UNIT;
	cub3d.pos_y = 6 * UNIT;
	cub3d.pos_angle = 0;
	cub3d.pos_dx = cos(cub3d.pos_angle);
	cub3d.pos_dy = sin(cub3d.pos_angle);
	draw_minimap_background(&cub3d);
	draw_viewport(&cub3d);
	mlx_key_hook(cub3d.mlx, &my_keyhook, &cub3d);
	mlx_close_hook(cub3d.mlx, &win_close, &cub3d);
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (EXIT_SUCCESS);
}

int	to_draw_a_line(t_cub3d *cub3d)
{
	t_point a = {20, 20, 0, 0x550055FF};
	t_point b = {200, 300, 0, 0x550055FF};
	draw_line(a, b, cub3d->minimap);
	return (0);
}