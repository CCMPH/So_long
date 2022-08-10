/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 11:21:57 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/10 14:19:23 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_direction	direction;

	game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			free_and_exit(game, "Game closed", EXIT_SUCCESS);
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			direction = UP;
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			direction = DOWN;
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			direction = LEFT;
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			direction = RIGHT;
		init_movement(game, direction);
	}
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init(BLOCKSIZE * game->data->map_columns,
			BLOCKSIZE * game->data->map_rows, "So_long", true);
	if (!game->mlx)
		free_and_exit(game, "Error\nmlx_init went wrong", EXIT_FAILURE);
	load_game(game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_close_hook(game->mlx, free_and_exit_cross, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

// void	on_exit(void)
// {
// 	system("leaks so_long");
// }

int	main(int ac, char **av)
{
	t_game	game;
	t_data	data;

	//atexit(on_exit);
	if (ac == 1)
		exit_msg("Error\nNot enough arguments");
	if (ac > 2)
		exit_msg("Error\nTo many arguments");
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game.data = &data;
	init_struct(&game);
	validate_map(av[1], &game);
	start_game(&game);
	return (0);
}
