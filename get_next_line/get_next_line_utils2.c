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
