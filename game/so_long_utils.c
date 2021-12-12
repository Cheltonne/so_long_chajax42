/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:07:10 by chajax            #+#    #+#             */
/*   Updated: 2021/12/05 22:55:07 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_is_valid(int keysym, t_data *data, t_vector *old_pos, int *moves)
{
	t_vector 	new_pos;

	if (keysym == XK_Down)
	{
		new_pos.y = (old_pos->y + 32) / 32;
		new_pos.x = (old_pos->x) / 32;
	}
	else if (keysym == XK_Up)
	{
		new_pos.y = (old_pos->y - 32) / 32;
		new_pos.x = (old_pos->x) / 32;
	}
	else if (keysym == XK_Left)
	{
		new_pos.x = (old_pos->x - 32) / 32;
		new_pos.y = (old_pos->y) / 32;
	}
	else if (keysym == XK_Right)
	{
		new_pos.x = (old_pos->x + 32) / 32;
		new_pos.y = (old_pos->y) / 32;
	}
	if (data->map[new_pos.y][new_pos.x] == WALL)
		return (0);
	*moves += 1;
	return (1);
}

void	check_victory(t_data *data)
{
	if (data->collectables == 0)
	{
		printf("ULTIMATE VICTORY FOR SIOPAO MAGDELEINE\n");
		end_game(data);
	}
}

void	check_interaction(int keysym, t_data *data, t_vector *old_pos)
{
	t_vector 	new_pos;

	if (keysym == XK_Down)
	{
		new_pos.y = (old_pos->y + 32) / 32;
		new_pos.x = (old_pos->x) / 32;
	}
	else if (keysym == XK_Up)
	{
		new_pos.y = (old_pos->y - 32) / 32;
		new_pos.x = (old_pos->x) / 32;
	}
	else if (keysym == XK_Left)
	{
		new_pos.x = (old_pos->x - 32) / 32;
		new_pos.y = (old_pos->y) / 32;
	}
	else if (keysym == XK_Right)
	{
		new_pos.x = (old_pos->x + 32) / 32;
		new_pos.y = (old_pos->y) / 32;
	}
	if (data->map[new_pos.y][new_pos.x] == COLLECTABLE)
	{
		data->collectables -= 1;
		redraw_bitmap(data, &new_pos, '0');
	}
	else if (data->map[new_pos.y][new_pos.x] == EXIT)
		check_victory(data);
}

int	check_movement(int keysym, t_data *data, t_vector *old_pos, int *moves)
{
	if (move_is_valid(keysym, data, old_pos, moves))
	{
		check_interaction(keysym, data, old_pos);
		return (1);
	}
	return (0);
}

int	input(int keysym, t_data *data)
{
	static int	moves;

	if (keysym == XK_Escape)
		end_game(data);
	if (keysym == XK_Down && check_movement(keysym, data, &data->sprite.coord, &moves))
		data->sprite.coord.y += 32;
	else if (keysym == XK_Up && check_movement(keysym, data, &data->sprite.coord, &moves))
		data->sprite.coord.y -= 32;
	else if (keysym == XK_Left && check_movement(keysym, data, &data->sprite.coord, &moves))
		data->sprite.coord.x -= 32;
	else if (keysym == XK_Right && check_movement(keysym, data, &data->sprite.coord, &moves))
		data->sprite.coord.x += 32;
	printf("%d move(s) made.\n", moves);
	return(1);
}
