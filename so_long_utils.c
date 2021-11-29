#include "so_long.h"

int	new_game(int fd, char *av, t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		printf("Couldn't initiate X server.");
		return (0);
	}
	check_map(fd, av, data);
	if(!win_init(data))
	{
		printf("Couldn't open window.");
		return (0);
	}
	create_assets(data);
	data->map = fill_map(fd, av, data);
	return (1);
}

void	*create_sprite(t_data *data, char *path)
{
	return (mlx_xpm_file_to_image(data->mlx_ptr, path, &data->sprite.width, &data->sprite.height));
}

int	input(int keysym, t_data *data)
{
	static int	movecount;

	if (keysym == XK_Escape)
	{
		destroy_assets(data);
		free_tilemap(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ground.img, data->sprite.coord.x, data->sprite.coord.y);
	printf("Move count: %d\n", movecount);
	if (keysym == XK_Down)
		data->sprite.coord.y += 32;
	else if (keysym == XK_Up)
		data->sprite.coord.y -= 32;
	else if (keysym == XK_Left)
		data->sprite.coord.x -= 32;
	else if (keysym == XK_Right)
		data->sprite.coord.x += 32;
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.img, data->sprite.coord.x, data->sprite.coord.y);
	movecount++;
	return(1);
}
