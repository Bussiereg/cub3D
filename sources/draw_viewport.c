#include "cub3d.h"

int	draw_sky(t_cub3d *cub3d)
{
	int	x;
	int	y;
	float	rgba[4];
	int sky_darker;
	int sky;

	sky = cub3d->color_C;
	sky_darker = 0x000910FF;
	calc_grad_steps(HEIGHT / 2, sky_darker, sky, &*rgba);
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH * 2)
		{
			mlx_put_pixel(cub3d->viewport, x, y, calc_grad_color(y, sky_darker, &*rgba));
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_ceiling(t_cub3d *cub3d)
{
	draw_sky(cub3d);
	/* int	x;
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
	} */
	return (0);
}

int	draw_floor(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
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
		if (x >= 0 && a >= 0 && x < WIDTH && a < HEIGHT)
			mlx_put_pixel(cub3d->viewport, x, a, calc_pix_color(i, text, text_x_pos, line_height));
		a++;
		i++;
	}
}


void	draw_viewport(t_cub3d *cub3d)
{

	draw_ceiling(cub3d);
	draw_floor(cub3d);
	draw_laser(cub3d);
	
	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 0);
}
