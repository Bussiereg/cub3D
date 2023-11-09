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
# define UNIT 10
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
	int				res_x;
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
	int				ray;

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

	mlx_image_t		*t_n;
	mlx_image_t		*t_s;
	mlx_image_t		*t_e;
	mlx_image_t		*t_w;

	int				color_c;
	int				color_f;

}	t_cub3d;

// draw_minimap.c
void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color);
void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color);
void	draw_minimap(t_cub3d *cub3d);

// draw_character.c
void	draw_direction(t_cub3d *cub3d, unsigned int color);
void	draw_character(t_cub3d *cub3d, unsigned int color);

// raycaster_main.c
void	raycaster(t_cub3d *cub3d, double ra);

// raycaster_distance.c
double	distance(double ax, double ay, double bx, double by);
void	dist_to_horizontal_wall(t_cub3d *cub3d, double xo, double yo, int lim);
void	dist_to_vertical_wall(t_cub3d *cub3d, double xo, double yo, int lim);
void	calculate_wall_distance(t_cub3d *cub3d);

// raycaster_calculus.c
void	check_vertical_line(t_cub3d *cub3d, double ra, int lim);
void	check_horizontal_line(t_cub3d *cub3d, double ra, int lim);
double	fix_angle(double a);
void	display(t_cub3d *cub3d);
void	draw_minimap_background(t_cub3d *cub3d);

// draw_viewport.c
int		draw_sky(t_cub3d *cub3d);
int		draw_ceiling(t_cub3d *cub3d);
void	draw_game(t_cub3d *cub3d);
int		draw_floor(t_cub3d *cub3d);
void	draw_viewport(t_cub3d *cub3d);
void	draw_line_textu(double line_height, int text_x_pos,
			mlx_image_t *text, t_cub3d *cub3d);

/// render.c
void	render(void *param);
void	render_viewport(t_cub3d *cub3d);

// parse_main.c
int		copy_map(char *file, t_cub3d *cub3d, int fd);
void	floodfill(t_cub3d *cub3d, int y, int x, char new_val);
int		check_wall(char **map, t_cub3d *cub3d);
int		parse_map(char *file, t_cub3d *cub3d);

// parse_info.c
int		read_pos(t_cub3d *cub3d, char c, int y, int i);
int		read_info(char *file, t_cub3d *cub3d);
int		all_info_read(t_cub3d *cub3d);
int		info_to_struct(char *line, t_cub3d *cub3d);
int		get_color_info(char *str);
int		line_to_map(int y, char *line, t_cub3d *cub3d);

// parse_utlis.c
int		duplicate_map(t_cub3d *cub3d);
char	**allocate_map(int y, int x);
int		read_map_size(int fd, t_cub3d *cub3d);
int		right_map_char(char c);
void	set_player_position(char map_char, int x, int y, t_cub3d *cub3d);

// color.c
void	calc_grad_steps(int i, int cl_a, int cl_b, float rgba[4]);
int		calc_pix_color(int steps, mlx_image_t *text, int x, int l_height);
int		calc_grad_color(int steps, int cl_a, float rgba[4]);

// keyhook.c
void	win_close(void *param);
void	my_keyhook(mlx_key_data_t keydata, void *param);

// close.c

void	terminate(char *str, t_cub3d *cub3d, int mlx, int map);
void	ft_free_tab(char **tab);

#endif