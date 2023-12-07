/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:48 by gbussier          #+#    #+#             */
/*   Updated: 2023/12/04 13:26:50 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	max_double(double *spritedistance)
{
	int		pos;
	int		i;
	double	temp;

	temp = spritedistance[0];
	i = 1;
	pos = 0;
	while (i < 3)
	{
		if (spritedistance[i] > temp)
		{
			temp = spritedistance[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	min_double(double *spritedistance)
{
	int		pos;
	int		i;
	double	temp;

	temp = spritedistance[0];
	i = 1;
	pos = 0;
	while (i < 3)
	{
		if (spritedistance[i] < temp)
		{
			temp = spritedistance[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	sprite_find_order(t_cub3d *cub3d, int i, double *spritedistance, int j)
{
	int		temp;

	temp = 4;
	while (j < 2)
	{
		i = 0;
		while (i < 2)
		{
			if (i == temp)
				i++;
			else
			{
				if (spritedistance[i] > spritedistance[i + 1])
					cub3d->spriteorder[j] = i;
				else
					cub3d->spriteorder[j] = i + 1;
				i++;
			}
		}
		temp = cub3d->spriteorder[j];
		j++;
	}
}

void	sort_sprite(t_cub3d *cub3d)
{
	double	spritedistance[3];
	int		i;

	i = 0;
	while (i < NUMSPRITES)
	{
		spritedistance[i] = ((cub3d->posx - cub3d->sprite[i].x) * (cub3d->posx
					- cub3d->sprite[i].x) + (cub3d->posy - cub3d->sprite[i].y)
				* (cub3d->posy - cub3d->sprite[i].y));
		i++;
	}
	sprite_find_order(cub3d, i, spritedistance, 0);
	cub3d->spriteorder[0] = max_double(spritedistance);
	cub3d->spriteorder[2] = min_double(spritedistance);
	cub3d->spriteorder[1] = 3 - cub3d->spriteorder[0] - cub3d->spriteorder[2];
}

mlx_image_t	*key_frame_selector(t_cub3d *cub3d)
{
	if (cub3d->key_frame / 3 == 1)
		return (cub3d->key1);
	if (cub3d->key_frame / 3 == 2)
		return (cub3d->key2);
	if (cub3d->key_frame / 3 == 3)
		return (cub3d->key3);
	if (cub3d->key_frame / 3 == 4)
		return (cub3d->key4);
	if (cub3d->key_frame / 3 == 5)
		return (cub3d->key5);
	if (cub3d->key_frame / 3 == 6)
		return (cub3d->key6);
	if (cub3d->key_frame / 3 == 7)
		return (cub3d->key7);
	if (cub3d->key_frame / 3 == 8)
		return (cub3d->key6);
	if (cub3d->key_frame / 3 == 9)
		return (cub3d->key5);
	if (cub3d->key_frame / 3 == 10)
		return (cub3d->key4);
	if (cub3d->key_frame / 3 == 11)
		return (cub3d->key3);
	if (cub3d->key_frame / 3 == 12)
		return (cub3d->key2);
	return (cub3d->key1);
}
