#include "cub3d.h"

void	calc_grad_steps(int i, int cl_a, int cl_b, float rgba[4])
{
	rgba[0] = (float)((uint8_t)(cl_b >> 24) - (uint8_t)(cl_a >> 24)) / (float)i;
	rgba[1] = (float)((uint8_t)(cl_b >> 16) - (uint8_t)(cl_a >> 16)) / (float)i;
	rgba[2] = (float)((uint8_t)(cl_b >> 8) - (uint8_t)(cl_a >> 8)) / (float)i;
	rgba[3] = (float)((uint8_t)(cl_b) - (uint8_t)(cl_a)) / (float)i;
}

int	calc_pix_color(int steps, mlx_image_t *text, int x, int l_height)
{
	int y;

	y = (steps * text->height / l_height);
	uint8_t r = text->pixels[((y * text->width + x) *(sizeof(int32_t)))];
	uint8_t g = text->pixels[((y * text->width + x)*(sizeof(int32_t)) +1)];
	uint8_t b = text->pixels[((y * text->width + x)*(sizeof(int32_t))+2)];
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

int	calc_grad_color(int steps, int cl_a, float rgba[4])
{
	return (((int)((uint8_t)(cl_a >> 24) + steps * rgba[0]) & 0xFF) << 24 |
			((int)((uint8_t)(cl_a >> 16) + steps * rgba[1]) & 0xFF) << 16 |
			((int)((uint8_t)(cl_a >> 8) + steps * rgba[2]) & 0xFF) << 8 |
			((int)((uint8_t)(cl_a >> 0) + steps * rgba[3]) & 0xFF) << 0);
}
