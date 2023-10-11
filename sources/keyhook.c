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

    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
        cub3d->pos_y -= 12;
		draw_minimap_background(cub3d);
	}
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
    {
	    cub3d->pos_x -= 12;
		draw_minimap_background(cub3d);
	}
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		draw_minimap_background(cub3d);
        cub3d->pos_y += 12;
	}
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		draw_minimap_background(cub3d);
        cub3d->pos_x += 12;
	}
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        win_close(param);
}