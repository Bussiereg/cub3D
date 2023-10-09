#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "MLX42.h"
# include <stdlib.h>
# include <errno.h>

// read map
// allocate map
// isolate line function

typedef struct point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct cub3d
{
	int 			res_x;
	int				res_y;

	mlx_image_t		*minimap;
	mlx_image_t		*viewport;
	mlx_t			*mlx;

	int				**map;
	int				m_size_x;
	int				m_size_y;
	
	char			*text_N;
	char			*text_S;
	char			*text_W;
	char			*text_E;
	int				color_S;
	int				color_F;

}	t_cub3d;

/* void	draw_map(t_fdf *fdf);
int		parse_map(char *file_name, t_map *map);
void	text_info(mlx_t *mlx, char *argv, t_map *map);

uint8_t	ft_atohex(char *str);
int		ft_ahextorgba(char *str);
void	calc_grad_steps(int i, int cl_a, int cl_b, float rgba[4]);
int		calc_grad_color(int steps, int cl_a, float rgba[4]);

void	draw_line(t_point point_a, t_point point_b, mlx_image_t *fdf);
void	draw_line_down(t_point a, t_point b, mlx_image_t *fdf);
void	draw_line_up(t_point a, t_point b, mlx_image_t *fdf);

int		count_split(char **split);
int		count_map_colums(char *file_name, t_map *map);
int		count_map_row(char *file_name, t_map *map);

int		free_split(char **split);

void	my_keyhook(mlx_key_data_t keydata, void *param);

void	terminate(char *str);
void	win_close(void *param);
int		free_grid(t_grid **grid, t_fdf *fdf); */
#endif