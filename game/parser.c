/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:25:47 by chajax            #+#    #+#             */
/*   Updated: 2021/12/05 20:01:14 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t one_strlen(int fd)
{
	size_t 	i;
	char	buf[10000];

	i = 0;
	read(fd, buf, 10000);
	while (buf[i++] != '\n')
		;
	close(fd);
	return (i - 1);
}

size_t line_count(int fd)
{
	size_t	i;
	size_t	j;
	char	*buf = calloc(10000, 1); //NE PAS OUBLIER DE REMPLACER CALLOC

	i = 0;
	j = 0;
	while (read(fd, buf, 10000))
		;
	while (buf[i])
	{
		if (buf[i++] == '\n')
			j++;
	}
	close(fd);
	free(buf);
	return (j);
}

void	check_map(int fd, char *av,  t_data *data)
{
	char 	*buf;
	size_t	i;

	i = 0;
	buf = calloc(10000, 1); // NE PAS OUBLIER DE REMPLACER PAR FT_CALLOC!!!!!!!!
	data->win_size.y = line_count(fd);
	fd = open(av, O_RDONLY);
	read(fd, buf, 10000);
	while (buf[i])
	{
		if (buf[i] == COLLECTABLE)
			data->collectables += 1;
		i++;
	}
	free(buf);
	close(fd);
	fd = open(av, O_RDONLY);
	data->win_size.x = one_strlen(fd);
}

char **fill_map(int fd, char *av, t_data *data)
{
	int	j;
	char	**map;

	j = 0;
	fd = open(av, O_RDONLY);
	map = malloc(sizeof(char) * data->win_size.y * data->win_size.x);
	if (!map)
		return (NULL);
	fd = open(av, O_RDONLY);
	while (j < data->win_size.y)
		map[j++] = get_next_line(fd);
	close(fd);
	return (map);
}
