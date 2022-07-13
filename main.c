/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 11:21:57 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/13 15:28:42 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_struct(t_game *game)
{
	game->data->map = NULL;
	game->data->collectables = 0;
	game->data->exits = 0;
	game->data->players = 0;
	game->data->rows = 0;
	game->data->columns = 0;
	game->data->map_rows = 0;
	game->data->map_columns = 0;
}


void	start_game(t_game *game)
{
	game->mlx = mlx_init(BLOCKSIZE * game->data->map_columns, BLOCKSIZE * game->data->map_rows, "So_long", true);
	if (!game->mlx)
		exit_msg("Error\nmlx_init went wrong");
	load_game(game);
	//hooks
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx); //deze nodig?
}


int	main(int ac, char **av)
{
	t_game	game;
	t_data	data;

	if (ac == 1)
		exit_msg("Error\nNot enough arguments");
	if (ac > 2)
		exit_msg("Error\nTo many arguments");
	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&data, sizeof(t_data));
	game.data = &data;
	init_struct(&game);
	validate_map(av[1], &game);
	start_game(&game);
	return (0);
}
