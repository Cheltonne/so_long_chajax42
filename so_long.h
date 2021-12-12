/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:56:08 by chajax            #+#    #+#             */
/*   Updated: 2021/12/05 23:30:23 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <mlx.h>
# include <unistd.h>

typedef enum e_tiletype{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

typedef struct s_vector{
int	x;
int	y;
}	t_vector;

typedef struct s_tile{
void		*img;
t_vector	coord;
int		width;
int		height;
char		*addr;
int		bpp;
int		size_line;
int		endian;
}	t_tile;

typedef struct s_data{
void		*mlx;
void		*win;
char		**map;
t_vector	win_size;
unsigned int	collectables;
t_tile		frame;
t_tile		sprite;
t_tile		ground;
t_tile		wall;
t_tile		collec;
t_tile		exit;
int		fd;
char		*av;
}	t_data;

int	new_game(int fd, char *av, t_data *data);
void	check_map(int fd, char *av, t_data *data);
size_t	one_strlen(int fd);
size_t	maplen(int fd);
char	**fill_map(int fd, char *av, t_data *data);
void	*create_sprite(t_data *data, char *path);
int	create_assets(t_data *data);
int	win_init(t_data *data);
void	img_to_img(t_tile *frame, t_tile *tile, int x, int y);
int	draw_frame(t_data *data);
int	buffer_frame(t_data *data);
int	input(int keysym, t_data *data);
int	destroy_assets(t_data *data);
void	end_game(t_data *data);
char	*get_next_line(int fd);
char	*ft_itoa(int nb);
void	redraw_bitmap(t_data *data, t_vector *pos, char new_value);
#endif
