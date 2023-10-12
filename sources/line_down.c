#include "cub3d.h"

void	draw_line_down_x_long(t_point a, t_point b, int *dist, mlx_image_t *img)
{
	float	f;
	int		i;
	float	rgba[4];

	i = 0;
	f = dist[0] / 2;
	calc_grad_steps(dist[0], a.color, b.color, &*rgba);
	while (a.x < b.x)
	{
		if (a.x >= 0 && a.y >= 0 && a.x < 900 && a.y <= 900)
			mlx_put_pixel(img, a.x, a.y, calc_grad_color(i, a.color, &*rgba));
		f = f - dist[1];
		if (f < 0)
		{
			a.y++;
			f = f + dist[0];
		}
		a.x++;
		i++;
	}
}

void	draw_line_down_y_long(t_point a, t_point b, int *dist, mlx_image_t *fdf)
{
	float	f;
	int		i;
	float	rgba[4];

	i = 0;
	f = dist[1] / 2;
	calc_grad_steps(dist[1], a.color, b.color, &*rgba);
	while (a.y < b.y)
	{
		if (a.x >= 0 && a.y >= 0 && a.x < 900 && a.y <= 900)
			mlx_put_pixel(fdf, a.x, a.y, calc_grad_color(i, a.color, &*rgba));
		f = f - dist[0];
		if (f < 0)
		{
			a.x++;
			f = f + dist[1];
		}
		a.y++;
		i++;
	}
}

void	draw_line_text(t_point a, t_point b, int x, mlx_image_t *text, t_cub3d *cub3d)
{
	float	f;
	int		i;
	float	rgba[4];

	int dx = b.x - a.x;
	int dy = b.y - a.y;
	i = 0;
	f = dy / 2;
	printf("***");
	//HERE FOR THE TEXTURE STUFF
	calc_grad_steps(dy, a.color, b.color, &*rgba);
	while (a.y < b.y)
	{
		if (a.x >= 0 && a.y >= 0 && a.x < 900 && a.y <= 900)
			mlx_put_pixel(cub3d->viewport, a.x, a.y, calc_pix_color(i, text, x, dy));
		f = f - dx;
		if (f < 0)
		{
			a.x++;
			f = f + dy;
		}
		a.y++;
		i++;
	}
}

void	draw_line_down(t_point a, t_point b, mlx_image_t *img)
{
	int		dx;
	int		dy;
	int		dist[2];

	dx = b.x - a.x;
	dy = b.y - a.y;
	dist[0] = dx;
	dist[1] = dy;
	if (dx > dy)
		draw_line_down_x_long(a, b, dist, img);
	else
		draw_line_down_y_long(a, b, dist, img);
}
