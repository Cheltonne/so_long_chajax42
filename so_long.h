#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <mlx.h>
# include <unistd.h>

typedef struct s_vector{
int x;
int y;
}	t_vector;

typedef struct s_tile{
void		*img;
int 		width;
int 		height;
t_vector	coord;
char		*addr;
int		bpp;
int		size_line;
int		endian;
}	t_tile;

typedef	struct	s_data{
void		*mlx_ptr;
void		*win_ptr;
char		**map;
t_vector	win_size;
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
int	win_init(t_data *data);
int	update(t_data *data);
int	render(t_data *data);
void	check_map(int fd, char *av, t_data *data);
void	*create_sprite(t_data *data, char *path);
int	create_assets(t_data *data);
int	destroy_assets(t_data *data);
int	input(int keysym, t_data *data);
size_t	one_strlen(int fd);
size_t	maplen(int fd);
char	**fill_map(int fd, char *av, t_data *data);
char	*get_next_line(int fd);
int	buffer_frame(t_data *data);
# endif
