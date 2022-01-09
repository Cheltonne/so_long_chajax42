/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:26:46 by phaslan           #+#    #+#             */
/*   Updated: 2021/12/25 16:31:04 by phaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../so_long.h"

char	*get_next_line(int fd, int free);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		has_return(char *str);
char	*last_line(char *str);

#endif
