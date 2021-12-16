/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:25:12 by chajax            #+#    #+#             */
/*   Updated: 2021/12/14 18:25:13 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	elements_are_valid(t_data *data)
{
	char	buf[10000];
	int		fd;

	fd = open(data->av, O_RDONLY);
	read(fd, buf, 10000);
	if (!ft_strchr(buf, PLAYER))
		return (0);
	if (!ft_strchr(buf, COLLECTABLE))
		return (0);
	if (!ft_strchr(buf, EXIT))
		return (0);
	return (1);
}

int	validate_map(t_data *data)
{
	if (!walls_are_valid(data))
		return (0);
	if (!shape_is_valid(data))
		return (0);
	if (!elements_are_valid(data))
		return (0);
	return (1);
}

char	**fill_map(int fd, char *av, t_data *data)
{
	int		j;
	char	**map;

	j = 0;
	map = malloc(sizeof(char)
			* (data->win_size.y * (data->win_size.x + 1)) + 1);
	if (!map)
		return (NULL);
	fd = open(av, O_RDONLY);
	while (j < data->win_size.y)
		map[j++] = get_next_line(fd);
	close(fd);
	return (map);
}
