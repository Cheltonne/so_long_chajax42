/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:25:47 by chajax            #+#    #+#             */
/*   Updated: 2021/12/16 01:47:56 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	one_strlen(int fd)
{
	size_t	i;
	char	*buf;

	i = 0;
	buf = calloc(1, 1);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
		{
			close(fd);
			free(buf);
			return (i);
		}
		i++;
	}
	close(fd);
	free(buf);
	return (i);
}

size_t	line_count(int fd)
{
	size_t	j;
	char	*buf;

	j = 0;
	buf = ft_calloc(1, 1);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			j++;
	}
	close(fd);
	free(buf);
	return (j);
}

void	check_map(int fd, char *av, t_data *data)
{
	char	*buf;

	buf = ft_calloc(1, 1);
	data->win_size.y = line_count(fd);
	fd = open(av, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (buf[0] == COLLECTABLE)
			data->collectables += 1;
	}
	free(buf);
	close(fd);
	fd = open(av, O_RDONLY);
	data->win_size.x = one_strlen(fd);
}

int	walls_are_valid(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	map = data->map;
	while (y < data->win_size.y)
	{
		if (y == 0 || y == data->win_size.y - 1)
		{
			x = 0;
			while (x < data->win_size.x - 1)
			{
				if (map[y][x++] != WALL)
					return (0);
			}
		}
		else if (map[y][0] != WALL || map[y][data->win_size.x - 1] != WALL)
			return (0);
		y++;
	}
	return (1);
}

int	shape_is_valid(t_data *data)
{
	int		y;
	size_t	line_len;
	size_t	next_line_len;

	y = 0;
	while (y < data->win_size.y - 1)
	{
		line_len = ft_strlen(data->map[y]);
		next_line_len = ft_strlen(data->map[y + 1]);
		if (line_len != next_line_len)
			return (0);
		y++;
	}
	return (1);
}
