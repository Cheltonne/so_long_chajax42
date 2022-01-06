/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:43:10 by chajax            #+#    #+#             */
/*   Updated: 2022/01/05 22:04:57 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
	{
		printf("Wrong number of arguments. Did you choose a map? ;)\n");
		return (1);
	}
	data.av = av[1];
	data.fd = open(av[1], O_RDONLY);
	if (!new_game(data.fd, data.av, &data))
		return (1);
	mlx_hook(data.win, KeyPress, KeyPressMask, input, &data);
	mlx_hook(data.win, DestroyNotify, KeyPressMask, end_game, &data);
	mlx_loop_hook(data.mlx, buffer_frame, &data);
	mlx_loop(data.mlx);
}
