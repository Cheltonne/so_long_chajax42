/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <chajax@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:52:06 by chajax            #+#    #+#             */
/*   Updated: 2021/09/30 10:28:40 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		o;
	int		total_len;
	char	*new;

	i = 0;
	o = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(sizeof(char) * total_len);
	if (!new)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			new[o++] = s1[i++];
		free(s1);
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
			new[o++] = s2[i++];
		new[o] = '\0';
	}
	return (new);
}

void	free_exp(char	**str)
{
	if (!*str)
		return ;
	free(*str);
	*str = NULL;
}

char	*check_eof(char *local, char **export, char *buf)
{
	free(buf);
	if (*export)
	{
		if (**export != '\0')
		{
			local = ft_strjoin(local, *export);
			free_exp(export);
			return (local);
		}
	}
	free_exp(export);
	return (NULL);
}

int	find_backline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	int				ret;
	char			*buf;
	char			*local;
	static char		*export[1024];

	if (fd < 0 || BUFFER_SIZE < 1 || !&export[fd])
		return (NULL);
	local = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (find_backline(export[fd]) == -1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 1)
			return (check_eof(local, &export[fd], buf));
		buf[ret] = '\0';
		export[fd] = ft_strjoin(export[fd], buf);
	}
	local = ft_substr(export[fd], 0, find_backline(export[fd]) + 1);
	export[fd] = ft_substr(export[fd], find_backline(export[fd]) + 1,
			ft_strlen(export[fd]) - find_backline(export[fd]));
	free(buf);
	return (local);
}
