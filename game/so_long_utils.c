/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:07:10 by chajax            #+#    #+#             */
/*   Updated: 2021/12/16 01:47:01 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_is_valid(int keysym, t_data *data, t_vector *old_pos, int *moves)
{
	t_vector	new_pos;

	if (keysym == KEY_DOWN || keysym == XK_Down)
		change_coordinates(old_pos, &new_pos, '+', 'y');
	else if (keysym == KEY_UP || keysym == XK_Up)
		change_coordinates(old_pos, &new_pos, '-', 'y');
	else if (keysym == KEY_LEFT || keysym == XK_Left)
		change_coordinates(old_pos, &new_pos, '-', 'x');
	else if (keysym == KEY_RIGHT || keysym == XK_Right)
		change_coordinates(old_pos, &new_pos, '+', 'x');
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
	t_vector	new_pos;

	if (keysym == KEY_DOWN || keysym == XK_Down)
		change_coordinates(old_pos, &new_pos, '+', 'y');
	else if (keysym == KEY_UP || keysym == XK_Up)
		change_coordinates(old_pos, &new_pos, '-', 'y');
	else if (keysym == KEY_LEFT || keysym == XK_Left)
		change_coordinates(old_pos, &new_pos, '-', 'x');
	else if (keysym == KEY_RIGHT || keysym == XK_Right)
		change_coordinates(old_pos, &new_pos, '+', 'x');
	if (data->map[new_pos.y][new_pos.x] == COLLECTABLE)
	{
		data->collectables -= 1;
		data->map[new_pos.y][new_pos.x] = EMPTY;
	}
	else if (data->map[new_pos.y][new_pos.x] == EXIT)
		check_victory(data);
}

int	check_movement(int keysym, t_data *data, t_vector *old_pos, int *moves)
{
	if (move_is_valid(keysym, data, old_pos, moves))
	{
		check_interaction(keysym, data, old_pos);
		if (*moves == 1)
			data->map[old_pos->y / 32][old_pos->x / 32] = EMPTY;
		return (1);
	}
	return (0);
}

int	input(int keysym, t_data *data)
{
	static int	moves;

	if (keysym == XK_Escape)
		end_game(data);
	if ((keysym == KEY_DOWN || keysym == XK_Down) && check_movement(keysym,
			data, &data->player.coord, &moves))
		process_move(DOWN, data);
	else if ((keysym == KEY_UP || keysym == XK_Up) && check_movement(keysym,
			data, &data->player.coord, &moves))
		process_move(UP, data);
	else if ((keysym == KEY_LEFT || keysym
			== XK_Left) && check_movement(keysym,
			data, &data->player.coord, &moves))
		process_move(LEFT, data);
	else if ((keysym == KEY_RIGHT || keysym
			== XK_Right) && check_movement(keysym,
			data, &data->player.coord, &moves))
		process_move(RIGHT, data);
	printf("%d move(s) made.\n", moves);
	return (1);
}
