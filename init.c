/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:02:47 by chajax            #+#    #+#             */
/*   Updated: 2021/11/29 17:14:48 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_assets(t_data *data)
{
	data->sprite.img = create_sprite(data, "./assets/demonrayquaza.xpm");
	data->sprite.coord.x = 32;
	data->sprite.coord.y = 32;
	data->ground.img = create_sprite(data, "./assets/ground.xpm");
	data->ground.addr = mlx_get_data_addr(data->ground.img, &data->ground.bpp, &data->ground.size_line, &data->ground.endian);
	data->wall.img = create_sprite(data, "./assets/wall.xpm");
	data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bpp, &data->wall.size_line, &data->wall.endian);
	data->collec.img = create_sprite(data, "./assets/collectible.xpm");
	data->collec.addr = mlx_get_data_addr(data->collec.img, &data->collec.bpp, &data->collec.size_line, &data->collec.endian);
	data->exit.img = create_sprite(data, "./assets/exit.xpm");
	data->exit.addr = mlx_get_data_addr(data->exit.img, &data->exit.bpp, &data->exit.size_line, &data->exit.endian);
	data->frame.img = mlx_new_image(data->mlx_ptr, data->win_size.x * 32, data->win_size.y * 32);
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp, &data->frame.size_line, &data->frame.endian);
	return (1);
}

int	destroy_assets(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->ground.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->collec.img);
	mlx_destroy_image(data->mlx_ptr, data->exit.img);
	mlx_destroy_image(data->mlx_ptr, data->frame.img);
	return (1);
}

int	win_init(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_size.x * 32, data->win_size.y * 32, "so_long alpha build 1.0");
	if (data->win_ptr == NULL)
	{
		free (data->mlx_ptr);
		return (0);
	}
	return (1);
}

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
	}
	return (1);
}

void	img_to_img(t_tile *frame, t_tile *tile, int x, int y)
{
	char	*f_pixel;
	char	*t_pixel;
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			f_pixel = frame->addr + (y++ * frame->size_line + x++ * (frame->bpp / 8));
			t_pixel = tile->addr + (i * tile->size_line + j * (tile->bpp / 8));
			*f_pixel = *t_pixel;
			j++;
		}
		i++;
	}
}

int	buffer_frame(t_data *data)
{
	draw_frame(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->frame.img, 0, 0);
	return (1);
}
