/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:02 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:04 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calc_grad_steps(int i, int cl_a, int cl_b, float rgba[4])
{
	rgba[0] = (float)((uint8_t)(cl_b >> 24) - (uint8_t)(cl_a >> 24)) / (float)i;
	rgba[1] = (float)((uint8_t)(cl_b >> 16) - (uint8_t)(cl_a >> 16)) / (float)i;
	rgba[2] = (float)((uint8_t)(cl_b >> 8) - (uint8_t)(cl_a >> 8)) / (float)i;
	rgba[3] = (float)((uint8_t)(cl_b) - (uint8_t)(cl_a)) / (float)i;
}

int	calc_pix_color(int steps, mlx_image_t *text, int x, int l_height)
{
	int		y;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	y = (steps * text->height / l_height);
	r = text->pixels[((y * text->width + x) * (sizeof(int32_t)))];
	g = text->pixels[((y * text->width + x) * (sizeof(int32_t)) + 1)];
	b = text->pixels[((y * text->width + x) * (sizeof(int32_t)) + 2)];
	a = text->pixels[((y * text->width + x) * (sizeof(int32_t)) + 3)];
	if (a == 0)
		return (0);
	return (r << 24 | g << 16 | b << 8 | a);
}

int	calc_grad_color(int steps, int cl_a, float rgba[4])
{
	return (((int)((uint8_t)(cl_a >> 24) + steps
		* rgba[0]) & 0xFF) << 24 | ((int)((uint8_t)(cl_a >> 16) + steps
		* rgba[1]) & 0xFF) << 16 | ((int)((uint8_t)(cl_a >> 8) + steps
		* rgba[2]) & 0xFF) << 8 | ((int)((uint8_t)(cl_a >> 0) + steps
		* rgba[3]) & 0xFF) << 0);
}

int	get_color_info(char *str)
{
	char	**rgb;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	rgb = ft_split(str, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_tab(rgb);
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

void	draw_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	int pix;

	pix = (y * img->width + x) * (sizeof(int32_t));
	img->pixels[pix] = (uint8_t)(color >> 24);
	img->pixels[pix + 1] = (uint8_t)(color >> 16);
	img->pixels[pix + 2] = (uint8_t)(color >> 8);
	img->pixels[pix + 3] = (uint8_t)(color & 0xFF);
}
