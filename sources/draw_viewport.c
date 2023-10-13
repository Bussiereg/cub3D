#include "cub3d.h"

int	draw_ceiling(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(cub3d->viewport, x, y, cub3d->color_C);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_floor(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < WIDTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(cub3d->viewport, x, y, cub3d->color_F);
			x++;
		}
		y++;
	}
	return (0);
}

void	draw_viewport(t_cub3d *cub3d)
{


	draw_ceiling(cub3d);
	draw_floor(cub3d);
	
	t_point a = {50, 50, 0, 0};
	t_point b = {50, 200, 0, 0};

	float ht = 400;

	a.y = 900 / 2 - ht * 2/3;
	b.y = 900 /2 + ht * 1/3;

	int i = 0;
	int xx = 0;
	while (i < 300)
	{
		draw_line_text(a, b, xx, cub3d->N, cub3d);
		xx = i * 10 / 300;
		i++;
		a.x++;
		b.x++;
	}

	a.x = 350;
	b.x = 350;

	ht = 400;

	a.y = 900 / 2 - ht * 2/3;
	b.y = 900 /2 + ht * 1/3;

	i = 0;
	xx = 0;
	while (i < 200)
	{
		a.y = 900 / 2 - ht * 2/3;
		b.y = 900 /2 + ht * 1/3;
		draw_line_text(a, b, xx, cub3d->N, cub3d);
		xx = i * 10 / 300;
		ht = ht - 0.7;
		i++;
		a.x++;
		b.x++;
	}

	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 900);
	//mlx_image_to_window(cub3d->mlx, t_N, 10, 10);
}
