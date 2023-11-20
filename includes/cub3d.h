/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:18:05 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/09 13:18:08 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define OFFSET 3
# define MOVESPEED 2
# define UNIT 10
# define HEIGHT 700
# define WIDTH 1400
# define ROTATE 26
# define ROTSPEED (M_PI / 52)
# define DR 60
# define RAD 0.0174533

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

	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			cameraX;
	double			rayDirX;
	double			rayDirY;
	int				mapX;
	int				mapY;

	double			sideDistY;
	double			sideDistX;
	double			deltaDistY;
	double			deltaDistX;


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

	mlx_image_t		*viewport;
	mlx_image_t		*minimap;
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

void	draw_character(t_cub3d *cub3d, unsigned int color);
void	draw_minimap(t_cub3d *cub3d);

// raycaster_main.c
void	south_north_wall(t_cub3d *cub3d, double line_height, double ra);
void	east_west_wall(t_cub3d *cub3d, double line_height, double ra);
void	raycaster(t_cub3d *cub3d, double ra);

// raycaster_distance.c
double	distance(double ax, double ay, double bx, double by);
void	dist_to_horizontal_wall(t_cub3d *cub3d, double xo, double yo, int lim);
void	dist_to_vertical_wall(t_cub3d *cub3d, double xo, double yo, int lim);
void	calculate_wall_distance(t_cub3d *cub3d);

// raycaster_calculus.c
double	fix_angle(double a);
void	check_horizontal_line(t_cub3d *cub3d, double ra, int lim);
void	check_vertical_line(t_cub3d *cub3d, double ra, int lim);

// draw_viewport.c
int		draw_sky(t_cub3d *cub3d);
int		draw_ceiling(t_cub3d *cub3d);
int		draw_floor(t_cub3d *cub3d);
void	draw_line_textu(double line_height, int text_x_pos,
			mlx_image_t *text, t_cub3d *cub3d);
void	draw_game(t_cub3d *cub3d);

/// render.c
void	render_viewport(t_cub3d *cub3d);
void	render(void *param);

// parse_main.c
int		copy_map(char *file, t_cub3d *cub3d);
void	floodfill(t_cub3d *cub3d, int y, int x, char new_val);
int		check_wall(char **map, t_cub3d *cub3d);
int		parse_map(char *file, t_cub3d *cub3d);

// parse_info.c
int		line_to_map(int y, char *line, t_cub3d *cub3d);
int		map_line(char *line);
int		info_to_struct(char *line, t_cub3d *cub3d);
int		all_info_read(t_cub3d *cub3d);
int		read_info(char *file, t_cub3d *cub3d);

// parse_textures.c
void	load_textures(mlx_texture_t	*texture, t_cub3d *cub3d, char **info);
void	set_player_position(char map_char, int x, int y, t_cub3d *cub3d);
int		get_color_info(char *str);

// parse_utlis.c
int		right_map_char(char c);
int		read_map_size(char *file, t_cub3d *cub3d, int fd);
char	**allocate_map(int y, int x);
int		duplicate_map(t_cub3d *cub3d);
int		open_file_to_line(char *file, t_cub3d *cub3d);

// color.c
void	calc_grad_steps(int i, int cl_a, int cl_b, float rgba[4]);
int		calc_pix_color(int steps, mlx_image_t *text, int x, int l_height);
int		calc_grad_color(int steps, int cl_a, float rgba[4]);

// keyhook_rotate.c
void	rotating_right(t_cub3d *cub3d);
void	rotating_left(t_cub3d *cub3d);

// keyhook_moving.c
void	moving_right(t_cub3d *cub3d);
void	moving_left(t_cub3d *cub3d);
void	moving_down(t_cub3d *cub3d);
void	moving_up(t_cub3d *cub3d);

// keyhook_main.c
void	win_close(void *param);
void	my_keyhook(mlx_key_data_t keydata, void *param);

// close.c
void	ft_free_tab(char **tab);
void	terminate(char *str, t_cub3d *cub3d, int mlx, int map);

#endif
