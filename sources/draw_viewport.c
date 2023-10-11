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
	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 900);
}
