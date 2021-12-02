/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:21:38 by chajax            #+#    #+#             */
/*   Updated: 2021/12/02 16:26:02 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	draw_frame(t_data *data)
{
	t_vector	map_pos;
	t_vector	index;

	index.y = 0;
	map_pos.y = 0;
	while(index.y < data->win_size.y)
	{
		map_pos.x = 0;
		index.x = 0;
		while (data->map[index.y][index.x] != '\n')
		{
			if (data->map[index.y][index.x] == WALL)
				img_to_img(&data->frame, &data->wall, map_pos.x, map_pos.y);
			else if (data->map[index.y][index.x] == EXIT)
				img_to_img(&data->frame, &data->exit, map_pos.x, map_pos.y);
			else if (data->map[index.y][index.x] == EMPTY)
				img_to_img(&data->frame, &data->ground, map_pos.x, map_pos.y);
			else if (data->map[index.y][index.x] == COLLECTABLE)
				img_to_img(&data->frame, &data->collec, map_pos.x, map_pos.y);
			map_pos.x += 32;
			index.x += 1;
		}
		map_pos.y += 32;
		index.y += 1;
		img_to_img(&data->frame, &data->sprite, data->sprite.coord.x, data->sprite.coord.y);
	}
	return (1);
}

void	img_to_img(t_tile *frame, t_tile *tile, int x, int y)
{
	char		*f_pixel;
	char		*t_pixel;
	t_vector	index;
	t_vector	pos;

	index.y = 0;
	pos.x = x;
	while (index.y < 32)
	{
		index.x = 0;
		x = pos.x;
		while (index.x < 32)
		{
			f_pixel = frame->addr + (y * frame->size_line + x++ * (frame->bpp / 8));
			t_pixel = tile->addr + (index.y * tile->size_line + index.x * (tile->bpp / 8));
			if (*(int *)f_pixel != *(int *)t_pixel)
				*(int *)f_pixel = *(int *)t_pixel;
			index.x++;
		}
		index.y++;
		y++;
	}
}

int	buffer_frame(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_frame(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->frame.img, 0, 0);
	return (1);
}

