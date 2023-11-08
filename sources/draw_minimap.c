#include "cub3d.h"

void	draw_laser(t_cub3d *cub3d, double rx, double ry)
{
	cub3d->pos_char.x = (int)cub3d->pos_x;
	cub3d->pos_char.y = (int)cub3d->pos_y;
	cub3d->pos_char.color = 0xFF8800FF;
	cub3d->pos_wall.x = (int)rx;
	cub3d->pos_wall.y = (int)ry;
	cub3d->pos_wall.color = 0xFFC380FF;
	draw_line(cub3d->pos_char, cub3d->pos_wall, cub3d->minimap);
}

void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color)
{
	int	new_x;
	int	new_y;

	new_y = y * UNIT;
	while (new_y < (y * UNIT) + UNIT)
	{
		new_x = x * UNIT;
		while (new_x < (x * UNIT) + UNIT)
		{
			if ((new_x == (x * UNIT) + UNIT - 1) || (new_y == (y * UNIT) + UNIT
					- 1))
				mlx_put_pixel(cub3d->minimap, new_x, new_y, 0x095275FF);
			else
				mlx_put_pixel(cub3d->minimap, new_x, new_y, color);
			new_x++;
		}
		new_y++;
	}
}

void	draw_character(t_cub3d *cub3d, unsigned int color)
{
	int	new_x;
	int	new_y;
	int	i;
	int	j;

	new_x = cub3d->pos_x - 1;
	new_y = cub3d->pos_y - 1;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
			mlx_put_pixel(cub3d->minimap, new_x + i, new_y + j++, color);
		i++;
	}
	i = 0;
	j = 0;
	while (j < (5))
	{
		mlx_put_pixel(cub3d->minimap, cub3d->pos_x + cub3d->pos_dx * j,
			cub3d->pos_y + cub3d->pos_dy * j, color);
		mlx_put_pixel(cub3d->minimap, cub3d->pos_x + cub3d->pos_dx * j - 1,
			cub3d->pos_y + cub3d->pos_dy * j, color);
		mlx_put_pixel(cub3d->minimap, cub3d->pos_x + cub3d->pos_dx * j,
			cub3d->pos_y + cub3d->pos_dy * j - 1, color);
		mlx_put_pixel(cub3d->minimap, cub3d->pos_x + cub3d->pos_dx * j,
			cub3d->pos_y + cub3d->pos_dy * j + 1, color);
		mlx_put_pixel(cub3d->minimap, cub3d->pos_x + cub3d->pos_dx * j + 1,
			cub3d->pos_y + cub3d->pos_dy * j, color);
		j++;
	}
}

void	draw_minimap(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < cub3d->m_size_y)
	{
		x = 0;
		while (x < cub3d->m_size_x)
		{
			if (cub3d->map[y][x] == '0')
				draw_tile(cub3d, x, y, 0xFFFFFFFF);
			else
				draw_tile(cub3d, x, y, 0x030209FF);
			x++;
		}
		y++;
	}
	draw_character(cub3d, 0xFF0000FF);
	mlx_image_to_window(cub3d->mlx, cub3d->minimap, 0, 0);
}
