/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:22 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:24 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_init(t_cub3d *cub3d)
{
	ft_bzero(cub3d, sizeof(*cub3d));
	// mlx_set_setting(MLX_FULLSCREEN, true);
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "SUBMOON", false);
	if (!cub3d->mlx)
		return (1);
	errno = 0;
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->background)
		return (1);
	cub3d->t_n = cub3d->background;
	cub3d->t_s = cub3d->background;
	cub3d->t_e = cub3d->background;
	cub3d->t_w = cub3d->background;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d		cub3d;

	if (argc != 2)
		terminate("Incorrect number of arguments!", &cub3d, 0, 0);
	if (cub3d_init(&cub3d) == 1)
		terminate("Init cub3d  mlx42 error", &cub3d, 0, 0);
	parse_map(argv[1], &cub3d);
	mlx_loop_hook(cub3d.mlx, &render, &cub3d);
	mlx_key_hook(cub3d.mlx, &my_keyhook, &cub3d);
	mlx_close_hook(cub3d.mlx, &win_close, &cub3d);
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	return (EXIT_SUCCESS);
}
