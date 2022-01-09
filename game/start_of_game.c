/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_of_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:02:47 by chajax            #+#    #+#             */
/*   Updated: 2022/01/09 23:28:01 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*create_sprite(t_data *data, t_tile *tile, char *path)
{
	void	*new_asset;
	int		size;

	size = 32;
	new_asset = mlx_xpm_file_to_image(data->mlx, path,
			&size, &size);
	if (!new_asset)
	{
		printf("Error\nCouldn't create asset: %s\n.", path);
		return ((void *)0);
	}
	tile->addr = mlx_get_data_addr
		(new_asset, &tile->bpp, &tile->size_line, &tile->endian);
	return (new_asset);
}

int	create_assets(t_data *data)
{
	data->player.img = create_sprite(data,
			&data->player, "./assets/redfront.xpm");
	data->front.img = create_sprite(data,
			&data->front, "./assets/redfront.xpm");
	data->back.img = create_sprite(data,
			&data->back, "./assets/back.xpm");
	data->rightt.img = create_sprite(data,
			&data->rightt, "./assets/right.xpm");
	data->leftt.img = create_sprite(data,
			&data->leftt, "./assets/left.xpm");
	data->ground.img = create_sprite(data,
			&data->ground, "./assets/ground.xpm");
	data->wall.img = create_sprite(data, &data->wall, "./assets/wall.xpm");
	data->collec.img = create_sprite(data,
			&data->collec, "./assets/collectible.xpm");
	data->exit.img = create_sprite(data, &data->exit, "./assets/exit.xpm");
	data->frame.img = mlx_new_image(data->mlx, data->win_size.x
			* 32, data->win_size.y * 32);
	data->frame.addr = mlx_get_data_addr(data->frame.img,
			&data->frame.bpp, &data->frame.size_line, &data->frame.endian);
	return (1);
}

int	win_init(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->win_size.x
			* 32, data->win_size.y * 32, "so_long alpha build 1.0");
	if (data->win == NULL)
	{
		free (data->mlx);
		return (0);
	}
	return (1);
}

void	character_init(t_data *data)
{
	int	i;
	int	o;

	o = 0;
	while (o < data->win_size.y)
	{
		i = 0;
		while (i < data->win_size.x)
		{
			if (data->map[o][i] == 'P')
			{
				data->player.coord.x = i * 32;
				data->player.coord.y = o * 32;
			}
			i++;
		}
		o++;
	}
}

int	new_game(int fd, char *av, t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		printf("Error\nCouldn't initiate X server.");
		return (0);
	}
	data->collectables = 0;
	check_map(fd, av, data);
	if (!win_init(data))
	{
		printf("Error\nCouldn't open window.");
		return (0);
	}
	create_assets(data);
	data->map = fill_map(fd, av, data);
	if (data->fd < 0 || !check_ext(data))
	{
		mlx_loop_end(data->mlx);
		return (0);
	}
	if (!validate_map(data))
		return (0);
	character_init(data);
	return (1);
}
