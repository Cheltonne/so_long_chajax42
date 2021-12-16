/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:56:33 by chajax            #+#    #+#             */
/*   Updated: 2021/12/16 00:11:36 by chajax           ###   ########.fr       */
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

void	end_game(t_data *data)
{
	destroy_assets(data);
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	exit(0);
}
