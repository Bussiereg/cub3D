#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42.h"
# include <stdlib.h>
# include <errno.h>
# define OFFSET 2
# define UNIT 5
# define PI2 M_PI/2
# define PI3 3*M_PI/2
# define HEIGHT 700
# define WIDTH 1400
# define ROTATE M_PI/26
# define DR ((M_PI / 180 * 70) / (WIDTH))

typedef struct point
{
	int		x;
	int		y;
	int		color;
}	t_point;

typedef struct cub3d
{
	int 			res_x;
	int				res_y;

	double			pos_x;
	double			pos_y;
	double			pos_angle;
	double			pos_dx;
	double			pos_dy;
	double			wall_x;
	double			wall_y;

	double			xo;
	double			yo;
	double			disth;
	double			hx;
	double			hy;
	double			distv;
	double			vx;
	double			vy;
	double			final_d;
	int				mx;
	int				my;

	t_point			pos_char;
	t_point			pos_wall;

	mlx_image_t		*minimap;
	mlx_image_t		*viewport;
	mlx_t			*mlx;

	char			**map;
	char			**map_check;
	int				map_line;
	int				m_size_x;
	int				m_size_y;
	
	mlx_image_t 		*N;
	mlx_image_t 		*S;
	mlx_image_t 		*E;
	mlx_image_t 		*W;

	int				color_C;
	int				color_F;

}	t_cub3d;

void	terminate(char *str, t_cub3d *cub3d, int mlx);
double fix_angle(double a);

// draw_minimap.c
void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color);
void	draw_character(t_cub3d *cub3d, unsigned int color);
void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color);
void	draw_minimap(t_cub3d *cub3d);

// draw.c
void display(t_cub3d *cub3d);
double distance(double ax, double ay, double bx, double by);
void	draw_minimap_background(t_cub3d *cub3d);
void	check_vertical_line(t_cub3d *cub3d, double ra, int lim);
void check_horizontal_line(t_cub3d *cub3d, double ra, int lim);
void dist_to_horizontal_wall(t_cub3d *cub3d, double xo, double yo, int lim);
void dist_to_vertical_wall(t_cub3d *cub3d, double xo, double yo, int lim);
double fix_angle(double a);
double distance(double ax, double ay, double bx, double by);
void	raycaster(t_cub3d *cub3d, double ra, int r);
void calculate_wall_distance(t_cub3d *cub3d);

// draw_viewport.c
void draw_game(t_cub3d *cub3d);

int		parse_map(char *file, t_cub3d *cub3d);
void	ft_free_tab(char **tab);
void	calc_grad_steps(int i, int cl_a, int cl_b, float rgba[4]);
int		calc_grad_color(int steps, int cl_a, float rgba[4]);
void	draw_line(t_point point_a, t_point point_b, mlx_image_t *fdf);
void	draw_line_down(t_point a, t_point b, mlx_image_t *fdf);
void	draw_line_up(t_point a, t_point b, mlx_image_t *fdf);
void	draw_viewport(t_cub3d *cub3d);
void	draw_background(t_cub3d *cub3d);
void	draw_line_textu(double line_height, int x, int text_x_pos, mlx_image_t *text, t_cub3d *cub3d);
void	render(void *param);


int	calc_pix_color(int steps, mlx_image_t *text, int x, int l_height);
void my_keyhook(mlx_key_data_t keydata, void *param);
void	win_close(void *param);

#endif