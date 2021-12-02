/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_of_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:02:47 by chajax            #+#    #+#             */
/*   Updated: 2021/12/02 16:26:59 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	create_assets(t_data *data)
{
	data->sprite.img = create_sprite(data, "./assets/redfront.xpm");
	data->sprite.addr = mlx_get_data_addr(data->sprite.img, &data->sprite.bpp, &data->sprite.size_line, &data->ground.endian);
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
				data->sprite.coord.x = i * 32;
				data->sprite.coord.y = o * 32;
			}
			i++;
		}
		o++;
	}
}

int	new_game(int fd, char *av, t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		printf("Couldn't initiate X server.");
		return (0);
	}
	check_map(fd, av, data);
	if(!win_init(data))
	{
		printf("Couldn't open window.");
		return (0);
	}
	create_assets(data);
	data->map = fill_map(fd, av, data);
	character_init(data);
	return (1);
}

void	*create_sprite(t_data *data, char *path)
{
	return (mlx_xpm_file_to_image(data->mlx_ptr, path, &data->sprite.width, &data->sprite.height));
}

