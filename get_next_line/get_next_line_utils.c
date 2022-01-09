/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:31:41 by phaslan           #+#    #+#             */
/*   Updated: 2021/12/25 16:40:23 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	x;
	char	*ret;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[x])
		ret[i++] = s2[x++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	has_return(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*last_line(char *str)
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\0')
		ret = malloc(sizeof(char) * (len + 1));
	if (str[len] == '\n')
		ret = malloc(sizeof(char) * (len + 2));
	if (!ret)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}
