/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:56:33 by chajax            #+#    #+#             */
/*   Updated: 2022/01/06 18:54:17 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destroy_assets(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->front.img);
	mlx_destroy_image(data->mlx, data->back.img);
	mlx_destroy_image(data->mlx, data->rightt.img);
	mlx_destroy_image(data->mlx, data->leftt.img);
	mlx_destroy_image(data->mlx, data->ground.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->collec.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_image(data->mlx, data->frame.img);
	return (1);
}

void	free_map(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->win_size.y)
		free (data->map[y++]);
	free (data->to_free);
}

int	end_game(t_data *data)
{
	destroy_assets(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	data->win = NULL;
	free_map(data);
	get_next_line(data->fd, 1);
	free(data->mlx);
	return (1);
}
