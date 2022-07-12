/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 11:21:57 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/12 15:30:19 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->collectables = 0;
	data->exits = 0;
	data->players = 0;
	data->rows = 0;
	data->columns = 0;
}

void	set_ground(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			mlx_image_to_window(data->mlx, data->ground_image, x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		y++;
	}
}

void	set_tree(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map[y][x] == '1')
				mlx_image_to_window(data->mlx, data->tree_image, x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		y++;
	}
}

// KIJKEN OF STRUCT IN STRUCT DE OPLOSSING KAN ZIJN?

void	set_textures(t_data *data)
{
	data->ground_texture = mlx_load_png("img/Grass.png");
	data->tree_texture = mlx_load_png("img/Trunk.png");
}

void	set_images(t_data *data)
{
	data->ground_image = mlx_texture_to_image(data->mlx, data->ground_texture);
	data->tree_image = mlx_texture_to_image(data->mlx, data->tree_texture);
}

void	load_map(t_data *data)
{
	set_ground(data);
	set_tree(data);
}

void	load_game(t_data *data)
{
	set_textures(data);
	set_images(data);
	load_map(data);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init(BLOCKSIZE * data->columns, BLOCKSIZE * data->rows, "So_long", true);
	if (!data->mlx)
		exit_msg("Error\nmlx_init went wrong");
	load_game(data);
	//hooks
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx); //deze nodig?
}


int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		exit_msg("Error\nNot enough arguments");
	if (ac > 2)
		exit_msg("Error\nTo many arguments");
	init_struct(&data);
	validate_map(av[1], &data);
	start_game(&data);
	return (0);
}
