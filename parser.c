#include "so_long.h"

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
	char	buf[10000];

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
	return (j);
}

void	check_map(int fd, char *av,  t_data *data)
{
	data->win_size.y = line_count(fd);
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
