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
		if (a.x >= 0 && a.y >= 0 && a.x < WIDTH && a.y <= HEIGHT)
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
		if (a.x >= 0 && a.y >= 0 && a.x < WIDTH && a.y <= HEIGHT)
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

void	draw_line_down(t_point a, t_point b, mlx_image_t *img)
{
	int	dx;
	int	dy;
	int	dist[2];

	dx = b.x - a.x;
	dy = b.y - a.y;
	dist[0] = dx;
	dist[1] = dy;
	if (dx > dy)
		draw_line_down_x_long(a, b, dist, img);
	else
		draw_line_down_y_long(a, b, dist, img);
}
