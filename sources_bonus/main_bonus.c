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

#include "cub3d_bonus.h"

int	cub3d_init(t_cub3d *cub3d)
{
	ft_bzero(cub3d, sizeof(*cub3d));
	mlx_set_setting(MLX_FULLSCREEN, true);
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
	cub3d->key_frame = 1;
	cub3d->wall_height = 1;
	return (0);
}

int	music_process(pa_simple *pa_stream, pa_sample_spec sample_spec)
{
	uint8_t buf[1024];
	size_t read_size;
	const char *file_path;
	
	file_path = "short.wav";
	int error;
	if (!(pa_stream = pa_simple_new(NULL, "PlayWav", PA_STREAM_PLAYBACK, NULL, "playback", &sample_spec, NULL, NULL, &error)))
	{
		printf("Erreur lors de la création du flux PulseAudio\n");
		return 1;
	}
	FILE *file = fopen(file_path, "rb");
	if (!file) 
	{
		perror("Erreur lors de l'ouverture du fichier .wav");
		pa_simple_free(pa_stream);
		return (1);
	}
	while ((read_size = fread(buf, 1, sizeof(buf), file)) > 0) 
	{
		if (pa_simple_write(pa_stream, buf, read_size, &error) < 0) 
		{
			fclose(file);
			pa_simple_free(pa_stream);
			return 1;
		}
	}
	fclose(file);
	pa_simple_free(pa_stream);
	return (0);
}

void handle_custom_signal(int signum) 
{
    if (signum == SIGUSR1) 
		exit(1);
}

int	main(int argc, char *argv[])
{
	t_cub3d		cub3d;

	if (argc != 2)
		terminate("Incorrect number of arguments!", &cub3d, 0, 0);
	if (cub3d_init(&cub3d) == 1)
		terminate("Init cub3d  mlx42 error", &cub3d, 0, 0);
	cub3d.music_pid = fork();
	if (cub3d.music_pid != 0)
	{
		parse_map(argv[1], &cub3d);
		mlx_loop_hook(cub3d.mlx, &render, &cub3d);
		mlx_mouse_hook(cub3d.mlx, &my_mousehook, &cub3d);
		mlx_key_hook(cub3d.mlx, &my_keyhook, &cub3d);
		mlx_close_hook(cub3d.mlx, &win_close, &cub3d);
		mlx_loop(cub3d.mlx);
		mlx_terminate(cub3d.mlx);
	}
	else
	{
		pa_simple *pa_stream = NULL;
		pa_sample_spec sample_spec;
		sample_spec.format = PA_SAMPLE_S16LE;
		sample_spec.channels = 2;
		sample_spec.rate = 45100;
		signal(SIGUSR1, handle_custom_signal);
		if (music_process(pa_stream, sample_spec) == 1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
