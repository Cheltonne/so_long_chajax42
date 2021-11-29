/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:02:47 by chajax            #+#    #+#             */
/*   Updated: 2021/11/28 23:10:48 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_assets(t_data *data)
{
	data->sprite.img = create_sprite(data, "./assets/demonrayquaza.xpm");
	data->sprite.coord.x = 32;
	data->sprite.coord.y = 32;
	data->ground.img = create_sprite(data, "./assets/ground.xpm");
	data->wall.img = create_sprite(data, "./assets/wall.xpm");
	data->collec.img = create_sprite(data, "./assets/collectible.xpm");
	data->exit.img = create_sprite(data, "./assets/exit.xpm");
	return (1);
}

int	destroy_assets(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprite.img);
	mlx_destroy_image(data->mlx_ptr, data->ground.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->collec.img);
	mlx_destroy_image(data->mlx_ptr, data->exit.img);
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

int	render(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.img, data->sprite.coord.x, data->sprite.coord.y);
	return (1);
}

int	update(t_data *data)
{
	t_vector	map_pos;
	t_vector	index;

	index.y = 0;
	map_pos.y = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while(index.y < data->win_size.y)
	{
		map_pos.x = 0;
		index.x = 0;
		while (data->map[index.y][index.x] != '\n')
		{
			if (data->map[index.y][index.x] == WALL)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.img, map_pos.x, map_pos.y);
			else if (data->map[index.y][index.x] == EXIT)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit.img, map_pos.x, map_pos.y);
			else if (data->map[index.y][index.x] == EMPTY)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground.img, map_pos.x, map_pos.y);
			else if (data->map[index.y][index.x] == COLLECTABLE)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collec.img, map_pos.x, map_pos.y);
			map_pos.x += 32;
			index.x += 1;
		}
		map_pos.y += 32;
		index.y += 1;
	}
	render(data);
	return (1);
}

void	img_pix_put(t_tile *tile, int x, int y, int color)
{
	char	*pixel;

	pixel = tile->addr + (y * tile->size_line + x * (tile->bpp / 8));
	*(int *)pixel = color;
}

int	buffer_frame(t_data *data)
{
	data->frame.img = mlx_new_image(data->mlx_ptr, data->win_size.x, data->win_size.y);
	data->frame.addr = mlx_get_data_addr(&data->frame.img, &data->frame.bpp, &data->frame.size_line, &data->frame.endian);
	img_pix_put(&data->frame, 0, 0, 0xFF0000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->frame.img, 0, 0);
	return (1);
}
