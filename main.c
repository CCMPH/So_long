/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 11:21:57 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/21 16:58:42 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h> //nodig voor printf

void	init_struct(t_game *game)
{
	game->data->map = NULL;
	game->data->collected = 0;
	game->data->tot_collectables = 0;
	game->data->nr_carrot = 0;
	game->data->exits = 0;
	game->data->players = 0;
	game->data->rows = 0;
	game->data->columns = 0;
	game->data->map_rows = 0;
	game->data->map_columns = 0;
	game->data->map_player_x = 0;
	game->data->map_player_y = 0;
	game->data->moves = 0;
}

int	check_movement_valid(t_game *game, t_direction direction)
{
	int	x;
	int	y;

	x = game->data->rabbit_img->instances->x / BLOCKSIZE;
	y = game->data->rabbit_img->instances->y / BLOCKSIZE;
	if (direction == UP && game->data->map[y - 1][x] == '1')
		return (0);
	if (direction == DOWN && game->data->map[y + 1][x] == '1')
		return (0);
	if (direction == LEFT && game->data->map[y][x - 1] == '1')
		return (0);
	if (direction == RIGHT && game->data->map[y][x + 1] == '1')
		return (0);
	return (1);
}

void	count_move(t_game *game)
{
	char	*move_str;

	move_str = NULL;
	game->data->moves++;
	ft_putnbr_fd(game->data->moves, 1);
	ft_putchar_fd('\n', 1);
	move_str = ft_itoa(game->data->moves);
	if (game->data->count_img)
		mlx_delete_image(game->mlx, game->data->count_img);
	game->data->count_img = mlx_put_string(game->mlx, move_str, 0, 0);
	free(move_str);
	if (game->data->count_img == NULL)
		exit(0);
}

void	move_player(t_game *game, char direction)
{
	if (direction == UP)
		game->data->rabbit_img->instances->y -= BLOCKSIZE;
	if (direction == DOWN)
		game->data->rabbit_img->instances->y += BLOCKSIZE;
	if (direction == LEFT)
		game->data->rabbit_img->instances->x -= BLOCKSIZE;
	if (direction == RIGHT)
		game->data->rabbit_img->instances->x += BLOCKSIZE;
	count_move(game);
}

int	find_location_carrot(t_game	*game)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;
	int	index;

	y = 1;
	index = 0;
	player_x = game->data->map_player_x;
	player_y = game->data->map_player_y;
	while (y < game->data->map_rows)
	{
		x = 0;
		while (x < game->data->map_columns)
		{
			if (x == player_x && y == player_y)
				return (index);
			if (game->data->map[y][x] == 'C' || game->data->map[y][x] == 'K')
				index++;
			x++;
		}
		y++;
	}
	return (index);
}

void	remove_collectable(t_game *game)
{
	int	index;

	index = find_location_carrot(game);
	game->data->carrot_img->instances[index].z = -1;
}


void	set_movement(t_game *game, t_direction direction)
{
	if (direction == UP)
		game->data->map_player_y--;
	else if (direction == DOWN)
		game->data->map_player_y++;
	else if (direction == LEFT)
		game->data->map_player_x--;
	else if (direction == RIGHT)
		game->data->map_player_x++;
	//count_move(game);
	if (game->data->map[game->data->map_player_y][game->data->map_player_x] == 'C')
	{
		game->data->nr_carrot++;
		game->data->map[game->data->map_player_y][game->data->map_player_x] = 'K';
		remove_collectable(game);
	}
	if (game->data->map[game->data->map_player_y][game->data->map_player_x] == 'E')
	{
		if (game->data->tot_collectables == game->data->nr_carrot)
			exit_msg("You won!");
	}
}

void	init_movement(t_game *game, t_direction direction)
{
	if (check_movement_valid(game, direction))
	{
		move_player(game, direction);
		set_movement(game, direction);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_direction	direction;

	game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			exit_msg("Game closed");
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
	game->mlx = mlx_init(BLOCKSIZE * game->data->map_columns, BLOCKSIZE * game->data->map_rows, "So_long", true);
	if (!game->mlx)
		exit_msg("Error\nmlx_init went wrong");
	load_game(game);
	mlx_key_hook(game->mlx, &key_hook, game);
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

// MORGEN EXIT PLAATJE PROBEREN TOE TE VOEGEN
// OPRUIMEN
// LEKKAGES!!
// SUBJECT NOG X GOED LEZEN
