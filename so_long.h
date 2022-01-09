/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:56:08 by chajax            #+#    #+#             */
/*   Updated: 2022/01/09 23:09:58 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10000
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"
# include <unistd.h>

typedef enum e_tiletype{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

typedef enum e_direction{
	UP = 'u',
	DOWN = 'd',
	RIGHT = 'r',
	LEFT = 'l',
}	t_direction;

enum e_keycode
{
	KEY_UP = 0x77,
	KEY_DOWN = 0x73,
	KEY_LEFT = 0x61,
	KEY_RIGHT = 0x64,
};

typedef struct s_vector{
	int	x;
	int	y;
}	t_vector;

typedef struct s_tile{
	void		*img;
	t_vector	coord;
	int			width;
	int			height;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}	t_tile;

typedef struct s_data{
	void			*mlx;
	void			*win;
	char			**map;
	char			**to_free;
	t_vector		win_size;
	unsigned int	collectables;
	t_tile			frame;
	t_tile			player;
	t_tile			front;
	t_tile			back;
	t_tile			rightt;
	t_tile			leftt;
	t_tile			ground;
	t_tile			wall;
	t_tile			collec;
	t_tile			exit;
	int				fd;
	char			*av;
}	t_data;

int		new_game(int fd, char *av, t_data *data);
void	error_handling(char *message);
void	check_map(int fd, char *av, t_data *data);
int		walls_are_valid(t_data *data);
int		shape_is_valid(t_data *data);
int		check_ext(t_data *data);
int		validate_map(t_data *data);
size_t	one_strlen(int fd);
size_t	maplen(int fd);
char	**fill_map(int fd, char *av, t_data *data);
void	*create_sprite(t_data *data, t_tile *tile, char *path);
int		create_assets(t_data *data);
int		win_init(t_data *data);
void	img_to_img(t_tile *frame, t_tile *tile, int x, int y);
int		draw_frame(t_data *data);
int		buffer_frame(t_data *data);
int		input(int keysym, t_data *data);
void	process_move(char direction, t_data *data);
void	change_coordinates(t_vector *old_pos,
			t_vector *new_pos, char op, char order);
int		destroy_assets(t_data *data);
int		end_game(t_data *data);
char	*get_next_line(int fd, int free);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		has_return(char *str);
#endif
