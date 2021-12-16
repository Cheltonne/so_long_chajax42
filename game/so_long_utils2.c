/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <chajax@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:42:22 by chajax            #+#    #+#             */
/*   Updated: 2021/12/16 01:44:01 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	process_move(char direction, t_data *data)
{
	if (direction == UP)
	{
		data->player.coord.y -= 32;
		data->player.addr = data->back.addr;
	}
	else if (direction == DOWN)
	{
		data->player.coord.y += 32;
		data->player.addr = data->front.addr;
	}
	else if (direction == LEFT)
	{
		data->player.coord.x -= 32;
		data->player.addr = data->leftt.addr;
	}
	else if (direction == RIGHT)
	{
		data->player.coord.x += 32;
		data->player.addr = data->rightt.addr;
	}
}

void	change_coordinates(t_vector *old_pos,
			t_vector *new_pos, char op, char order)
{
	if (order == 'y')
	{
		new_pos->x = (old_pos->x) / 32;
		if (op == '+')
			new_pos->y = (old_pos->y + 32) / 32;
		else
			new_pos->y = (old_pos->y - 32) / 32;
	}
	else
	{
		new_pos->y = (old_pos->y) / 32;
		if (op == '+')
			new_pos->x = (old_pos->x + 32) / 32;
		else
			new_pos->x = (old_pos->x - 32) / 32;
	}
}
