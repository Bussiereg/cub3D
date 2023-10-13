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

void	draw_line_textu(int line_height, int x, int text_x_pos, mlx_image_t *text, t_cub3d *cub3d)
{

	int	i;
	int	a;
	int	b;

	a = HEIGHT / 2 - line_height / 2;
	b = HEIGHT / 2 + line_height / 2;

	i = 0;
	while (a < b)
	{
		if (x >= 0 && a >= 0 && x < WIDTH && a <= HEIGHT)
			mlx_put_pixel(cub3d->viewport, x, a, calc_pix_color(i, text, text_x_pos, line_height));
		a++;
		i++;
	}
}

void	draw_viewport(t_cub3d *cub3d)
{

	draw_ceiling(cub3d);
	draw_floor(cub3d);
	
	int i = 0;
	float x = 50;
	float line_height;
	float w_d = 4;

	line_height = HEIGHT / (w_d + cub3d->w_d_offset);
	int xx = 0;
	while (i < 200)
	{
		draw_line_textu(line_height, i + x, xx, cub3d->S, cub3d);
		xx = i * cub3d->S->height / 200;
		i++;
	}

	i = 0;
	x = 250;
	w_d = 6;
	line_height = HEIGHT / (w_d + cub3d->w_d_offset);
	xx = 0;
	while (i < 100)
	{
		draw_line_textu(line_height, i + x, xx, cub3d->W, cub3d);
		xx = i * cub3d->W->height / 100;
		line_height -= 0.5;
		i++;
	}

	i = 0;
	x = 350;
	line_height = 100;
	xx = 0;
	while (i < 100)
	{
		draw_line_textu(line_height, i + x, xx, cub3d->S, cub3d);
		xx = i * cub3d->S->height / 100;
		i++;
	}

	i = 0;
	x = 450;
	line_height = 100;
	xx = 0;
	while (i < 100)
	{
		draw_line_textu(line_height, i + x, xx, cub3d->E, cub3d);
		xx = i * cub3d->E->height / 100;
		line_height += 0.5;
		i++;
	}

	i = 0;
	x = 550;
	line_height = 150;
	xx = 0;
	while (i < 100)
	{
		draw_line_textu(line_height, i + x, xx, cub3d->E, cub3d);
		xx = i * cub3d->E->height / 100;
		line_height += 0.5;
		i++;
	}




	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, HEIGHT);
}
