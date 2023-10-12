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

	float ht = 300;

	a.y = 900 / 2 - ht / 2;
	b.y = 900 /2 + ht / 2;

	int i = 0;
	int xx = 0;
	while (i < 300)
	{
		draw_line_text(a, b, xx, N, cub3d);
		xx = i * 300 / 300;
		i++;
		a.x++;
		b.x++;
	}

	a.x = 350;
	b.x = 350;

	ht = 300;

	a.y = 900 / 2 - ht / 2;
	b.y = 900 /2 + ht / 2;

	i = 0;
	xx = 0;
	while (i < 300)
	{
		a.y = 900 / 2 - ht / 2;
		b.y = 900 /2 + ht / 2;
		draw_line_text(a, b, xx, N, cub3d);
		xx = i * 300 / 300;
		ht = ht - 0.5;
		i++;
		a.x++;
		b.x++;
	}

	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 900);
	//mlx_image_to_window(cub3d->mlx, t_N, 10, 10);
}
