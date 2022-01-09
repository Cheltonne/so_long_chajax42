/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:52:18 by chajax            #+#    #+#             */
/*   Updated: 2022/01/09 23:03:58 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ext(t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(data->av);
	while (i < 4)
	{
		if (!ft_strchr(".ber", data->av[len]))
		{
			printf("Error\nWrong file extension.\n");
			return (0);
		}
		len--;
		i++;
	}
	return (1);
}
