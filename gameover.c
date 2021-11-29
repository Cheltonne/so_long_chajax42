/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:56:33 by chajax            #+#    #+#             */
/*   Updated: 2021/11/28 23:03:22 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
