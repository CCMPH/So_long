/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 11:21:57 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 13:15:39 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data		*data;
	t_direction	direction;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			free_and_exit(data, "Game closed", EXIT_SUCCESS);
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			direction = UP;
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			direction = DOWN;
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			direction = LEFT;
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			direction = RIGHT;
		init_movement(data, direction);
	}
}

static void	start_game(t_data *data)
{
	data->mlx = mlx_init(BLOCKSIZE * data->columns,
			BLOCKSIZE * data->rows, "So_long", true);
	if (!data->mlx)
		free_and_exit(data, "Error\nmlx_init went wrong", EXIT_FAILURE);
	load_game(data);
	mlx_key_hook(data->mlx, &key_hook, data);
	mlx_close_hook(data->mlx, free_and_exit_cross, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

// void	on_exit(void)
// {
// 	system("leaks so_long");
// }

int	main(int ac, char **av)
{
	t_data	data;

	//atexit(on_exit);
	if (ac == 1)
		exit_msg("Error\nNot enough arguments");
	if (ac > 2)
		exit_msg("Error\nTo many arguments");
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	init_struct(&data);
	validate_map(av[1], &data);
	start_game(&data);
	return (0);
}
