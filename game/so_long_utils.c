/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:07:10 by chajax            #+#    #+#             */
/*   Updated: 2021/12/02 16:26:49 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	input(int keysym, t_data *data)
{
	static int	movecount;

	if (keysym == XK_Escape)
	{
		destroy_assets(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	printf("Move count: %d\n", movecount);
	if (keysym == XK_Down)
		data->sprite.coord.y += 32;
	else if (keysym == XK_Up)
		data->sprite.coord.y -= 32;
	else if (keysym == XK_Left)
		data->sprite.coord.x -= 32;
	else if (keysym == XK_Right)
		data->sprite.coord.x += 32;
	movecount++;
	return(1);
}
