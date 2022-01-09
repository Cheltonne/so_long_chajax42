/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:25:12 by chajax            #+#    #+#             */
/*   Updated: 2022/01/09 22:17:21 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	elements_are_valid(t_data *data, int map_size)
{
    char    buf[map_size + 1];
    int		fd;
    int     p;
    int     i;

    fd = open(data->av, O_RDONLY);
    read(fd, buf, map_size);
    buf[map_size] = '\0';
    if (!ft_strchr(buf, COLLECTABLE))
        return (0);
    if (!ft_strchr(buf, EXIT))
        return (0);
    p = 0;
    i = 0;
    while (buf[i])
    {
        if (buf[i] == PLAYER)
            p++;
        i++;
    }
    if (p != 1)
        return (0);
    return (1);
}

void    error_handling(char *message)
{
    printf("Error\n%s\n", message);
}

int	validate_map(t_data *data)
{
    int map_size;

    map_size = data->win_size.x * data->win_size.y;
    if (!walls_are_valid(data))
    {
        error_handling("There is a problem with the walls.");
        return(0);
    }
    if (!shape_is_valid(data))
    {
        error_handling("There is a problem with the shape of the map.");
        return(0);
    }
    if (!elements_are_valid(data, map_size))
    {
        error_handling("There is a problem with the elements of the map.");
        return(0);
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
