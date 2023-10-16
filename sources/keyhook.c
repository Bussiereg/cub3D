#include "cub3d.h"

void	win_close(void *param)
{
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->minimap);
	mlx_terminate(((t_cub3d *)param)->mlx);
	exit (EXIT_SUCCESS);
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
    t_cub3d *cub3d = (t_cub3d*)param;

    if ((keydata.key == MLX_KEY_UP || keydata.key == 87) && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		if ((cub3d->map[(int)(cub3d->pos_y + (cub3d->pos_dy  * OFFSET)) / UNIT][(int)(cub3d->pos_x + (cub3d->pos_dx * OFFSET))/ UNIT]) == '0')
		{
      		cub3d->pos_y += cub3d->pos_dy * OFFSET;
			cub3d->pos_x += cub3d->pos_dx * OFFSET;
			cub3d->w_d_offset -= 0.1;
			//printf("px: %f\npy: %f\npdx: %f\npdy: %f\nangle: %f\n\n", cub3d->pos_x, cub3d->pos_y, cub3d->pos_dx, cub3d->pos_dy, cub3d->pos_angle);	
			draw_minimap_background(cub3d);
			//draw_viewport(cub3d);
		}
	}
    else if ((keydata.key == MLX_KEY_DOWN || keydata.key == 83) && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		if ((cub3d->map[(int)(cub3d->pos_y - (cub3d->pos_dy * OFFSET)) / UNIT][(int)(cub3d->pos_x - (cub3d->pos_dx * OFFSET))/ UNIT]) == '0')
		{
      		cub3d->pos_y -= cub3d->pos_dy * OFFSET;
			cub3d->pos_x -= cub3d->pos_dx * OFFSET;
			cub3d->w_d_offset += 0.1;
			//printf("px: %f\npy: %f\npdx: %f\npdy: %f\nangle: %f\n\n", cub3d->pos_x, cub3d->pos_y, cub3d->pos_dx, cub3d->pos_dy, cub3d->pos_angle);	
			draw_minimap_background(cub3d);
			//draw_viewport(cub3d);
		}
	}
    else if ((keydata.key == MLX_KEY_LEFT || keydata.key == 65) && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
    {
		cub3d->pos_angle -= (PI / 26);
		if (cub3d->pos_angle < 0)
			cub3d->pos_angle += (2 * PI);
		cub3d->pos_dx = cos(cub3d->pos_angle);
		cub3d->pos_dy = sin(cub3d->pos_angle);
		// printf("px: %f\npy: %f\npdx: %f\npdy: %f\nangle: %f\n\n", cub3d->pos_x, cub3d->pos_y, cub3d->pos_dx, cub3d->pos_dy, cub3d->pos_angle);	
		draw_minimap_background(cub3d);
		//draw_viewport(cub3d);
	}
    else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == 68) && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		cub3d->pos_angle += (PI / 26);
		if (cub3d->pos_angle >= (2 * PI))
			cub3d->pos_angle -= (2 * PI);
		cub3d->pos_dx = cos(cub3d->pos_angle);
		cub3d->pos_dy = sin(cub3d->pos_angle);
		// printf("px: %f\npy: %f\npdx: %f\npdy: %f\nangle: %f\n\n", cub3d->pos_x, cub3d->pos_y, cub3d->pos_dx, cub3d->pos_dy, cub3d->pos_angle);	
		draw_minimap_background(cub3d);
		//draw_viewport(cub3d);
	}
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        win_close(param);
}