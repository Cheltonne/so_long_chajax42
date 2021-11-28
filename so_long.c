/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:43:10 by chajax            #+#    #+#             */
/*   Updated: 2021/11/26 21:29:00 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_nothing(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->win_size.x, data->win_size.y, 0x0AAFFFF, "currently doing nothing. :)");
	return (1);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
	{
		printf("Wrong number of arguments. Did you choose a map? ;)\n");
		return (1);
	}
	render(&data);
	data.av = av[1];
	data.fd = open(av[1], O_RDONLY);
	if (!new_game(data.fd, data.av, &data))
		return (1);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &input, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop_hook(data.mlx_ptr, &update, &data);
	mlx_loop(data.mlx_ptr);
}
