/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:21:38 by chajax            #+#    #+#             */
/*   Updated: 2021/12/16 00:24:58 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			f_pixel = frame->addr + (y * frame->size_line + (x++)
					* (frame->bpp / 8));
			t_pixel = tile->addr + (index.y * tile->size_line
					+ index.x * (tile->bpp / 8));
			if (*(int *)f_pixel != *(int *)t_pixel)
				*(int *)f_pixel = *(int *)t_pixel;
			index.x++;
		}
		index.y++;
		y++;
	}
}

int	draw_frame(t_data *data)
{
	t_vector	i;

	i.y = 0;
	while (i.y < data->win_size.y)
	{
		i.x = 0;
		while (data->map[i.y][i.x] != '\n')
		{
			if (data->map[i.y][i.x] == WALL)
				img_to_img(&data->frame, &data->wall, i.x * 32, i.y * 32);
			else if (data->map[i.y][i.x] == EXIT)
				img_to_img(&data->frame, &data->exit, i.x * 32, i.y * 32);
			else if (data->map[i.y][i.x] == EMPTY)
				img_to_img(&data->frame, &data->ground, i.x * 32, i.y * 32);
			else if (data->map[i.y][i.x] == COLLECTABLE)
				img_to_img(&data->frame, &data->collec, i.x * 32, i.y * 32);
			i.x += 1;
		}
			i.y += 1;
	}
	img_to_img(&data->frame, &data->player, data->player.coord.x,
		data->player.coord.y);
	return (1);
}

int	buffer_frame(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_frame(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.img, 0, 0);
	return (1);
}
