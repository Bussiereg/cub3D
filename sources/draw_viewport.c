#include "cub3d.h"

void	draw_viewport(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < 450)
	{
		x = 0;
		while (x < 900)
		{
			mlx_put_pixel(cub3d->viewport, x, y, cub3d->color_C);
			x++;
		}
		y++;
	}
	y = 450;
	x = 0;
	while (y < 900)
	{
		x = 0;
		while (x < 900)
		{
			mlx_put_pixel(cub3d->viewport, x, y, cub3d->color_F);
			x++;
		}
		y++;
	}
	cub3d->N = mlx_texture_to_image(cub3d->mlx, cub3d->text_N);
	mlx_image_t *N = cub3d->N;

	t_point a = {50, 50, 0, 0};
	t_point b = {50, 200, 0, 0};
	draw_line_text(a, b, 5, N, cub3d);
	a.x = 51;
	b.x = 51;
	draw_line_text(a, b, 5, N, cub3d);
	a.x = 52;
	b.x = 52;
	draw_line_text(a, b, 5, N, cub3d);
	a.x = 53;
	b.x = 53;
	draw_line_text(a, b, 5, N, cub3d);
	a.x = 54;
	b.x = 54;
	draw_line_text(a, b, 5, N, cub3d);
	a.x = 55;
	b.x = 55;
	draw_line_text(a, b, 6, N, cub3d);

	a.x = 56;
	b.x = 56;
	draw_line_text(a, b, 6, N, cub3d);
	a.x = 57;
	b.x = 57;
	draw_line_text(a, b, 6, N, cub3d);
	a.x = 58;
	b.x = 58;
	draw_line_text(a, b, 6, N, cub3d);


	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 900);
	//mlx_image_to_window(cub3d->mlx, t_N, 10, 10);
}
