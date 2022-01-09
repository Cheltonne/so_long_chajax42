/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:25:12 by chajax            #+#    #+#             */
/*   Updated: 2022/01/09 23:14:49 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_player(char *buf)
{
	int		p;
	int		i;

	p = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == PLAYER)
			p++;
		i++;
	}
	if (p != 1)
	{
		free(buf);
		if (p < 1)
			error_handling("There is no player spawning point.");
		else
			error_handling("There are more than one player spawning points.");
		return (0);
	}
	return (1);
}

int	elements_are_valid(t_data *data, int map_size)
{
	char	*buf;
	int		fd;

	buf = malloc(map_size + 1);
	if (!buf)
		return (0);
	buf[map_size] = '\0';
	fd = open(data->av, O_RDONLY);
	read(fd, buf, map_size);
	if (!ft_strchr(buf, COLLECTABLE))
	{
		free(buf);
		return (0);
	}
	if (!ft_strchr(buf, EXIT))
	{
		free(buf);
		return (0);
	}
	if (!check_player(buf))
		return (0);
	free(buf);
	return (1);
}

void	error_handling(char *message)
{
	printf("Error\n%s\n", message);
}

int	validate_map(t_data *data)
{
	int	map_size;

	map_size = data->win_size.x * data->win_size.y;
	if (!walls_are_valid(data))
	{
		error_handling("There is a problem with the walls.");
		return (0);
	}
	if (!shape_is_valid(data))
	{
		error_handling("There is a problem with the shape of the map.");
		return (0);
	}
	if (!elements_are_valid(data, map_size))
	{
		error_handling("There is a problem with the elements of the map.");
		return (0);
	}
	return (1);
}

char	**fill_map(int fd, char *av, t_data *data)
{
	int		j;
	char	**map;

	j = 0;
	map = malloc(sizeof(char *)
			* data->win_size.y);
	data->to_free = map;
	if (!map)
		return (NULL);
	fd = open(av, O_RDONLY);
	while (j < data->win_size.y)
		map[j++] = get_next_line(fd, 0);
	close(fd);
	return (map);
}
