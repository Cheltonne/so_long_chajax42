/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <chajax@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:45:04 by chajax            #+#    #+#             */
/*   Updated: 2021/09/25 15:33:57 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../so_long.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	if (!s)
		return ;
	while (n--)
		*(str++) = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;

	new = malloc(size * nmemb);
	if (!new)
		return (NULL);
	ft_bzero(new, nmemb * size);
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	src_len;

	i = -1;
	src_len = ft_strlen(src);
	if (!dst || src[src_len])
		return (src_len);
	while (dstsize-- && src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	else if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	else if (len <= (ft_strlen(s) - start))
	{
		new = malloc(sizeof(char) * len + 1);
		if (!new)
			return (NULL);
		ft_strlcpy(new, &s[start], len + 1);
		return (new);
	}
	else
	{
		new = malloc(sizeof(char) * ft_strlen(s) - start + 1);
		if (!new)
			return (NULL);
		ft_strlcpy(new, s + start, ft_strlen(s) + 1);
		free((char *)s);
		return (new);
	}
}
