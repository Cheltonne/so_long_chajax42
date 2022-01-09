/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:15:33 by phaslan           #+#    #+#             */
/*   Updated: 2021/12/25 17:15:46 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_str(char *str)
{
	char	*ret;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (str[i] != '\0' && str[i] != '\n' )
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!ret)
		return (NULL);
	while (str[i++] != '\0')
	{
		ret[x] = str[i];
		x++;
	}
	ret[x] = '\0';
	free (str);
	return (ret);
}

char	*redline(int fd, char *str)
{
	int		count;
	char	*buff;

	count = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!(has_return(str)) && count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
			break ;
		buff[count] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd, int last)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (last)
	{
		free(str);
		return (NULL);
	}
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = redline(fd, str);
	if (!str)
		return (NULL);
	ret = last_line(str);
	str = next_str(str);
	return (ret);
}
