/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:56:33 by chajax            #+#    #+#             */
/*   Updated: 2021/12/02 16:25:22 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	free_tilemap(t_data *data)
{
	char	**tilemap;

	tilemap = data->map;
	while (*data->map != NULL)
	{
		free(*data->map);
		data->map++;
	}
	free (tilemap);
}
