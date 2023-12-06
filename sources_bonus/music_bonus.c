/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:57:08 by gbussier          #+#    #+#             */
/*   Updated: 2023/12/06 16:57:10 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	read_music(pa_simple *pa_stream, FILE *file, int error)
{
	size_t		read_size;
	uint8_t		buf[1024];

	read_size = fread(buf, 1, sizeof(buf), file);
	while (read_size > 0) 
	{
		if (pa_simple_write(pa_stream, buf, read_size, &error) < 0) 
		{
			fclose(file);
			pa_simple_free(pa_stream);
			return (1);
		}
		read_size = fread(buf, 1, sizeof(buf), file);
	}
	return (0);
}

int	music_process(pa_simple *pa_stream, pa_sample_spec sample_spec)
{
	const char	*file_path;
	int			error;
	FILE		*file;

	file_path = "music.wav";
	pa_stream = pa_simple_new(NULL, "PlayWav", PA_STREAM_PLAYBACK,
			NULL, "playback", &sample_spec, NULL, NULL, &error);
	if (!pa_stream)
	{
		printf("Error while creating the audiostream\n");
		return (1);
	}
	file = fopen(file_path, "rb");
	if (!file) 
	{
		perror("Error while opening the file .wav");
		pa_simple_free(pa_stream);
		return (1);
	}
	if (read_music(pa_stream, file, error))
		return (1);
	fclose(file);
	pa_simple_free(pa_stream);
	return (0);
}
