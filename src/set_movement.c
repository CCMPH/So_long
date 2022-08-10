/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_movement.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:09:20 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/10 11:52:51 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	set_new_exit(t_game	*game)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	while (y < game->data->map_rows)
	{
		x = 0;
		while (x < game->data->map_columns)
		{
			if (game->data->map[y][x] == 'E')
			{
				index = mlx_image_to_window(game->mlx, game->data->exit2_img,
						x * BLOCKSIZE, y * BLOCKSIZE);
				if (index == -1)
					free_and_exit(game, "ERROR", EXIT_FAILURE);
				game->data->exit2_img->instances[index].z = 4;
			}
			x++;
		}
		y++;
	}
}

void	edit_exit(t_game *game)
{
	mlx_delete_image(game->mlx, game->data->exit_img);
	set_new_exit(game);
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
	if (game->data->map[game->data->map_player_y]
		[game->data->map_player_x] == 'C')
	{
		game->data->nr_carrot++;
		game->data->map[game->data->map_player_y]
		[game->data->map_player_x] = 'K';
		remove_collectable(game);
		if (game->data->nr_carrot == game->data->tot_collectables)
			edit_exit(game);
	}
	if (game->data->map[game->data->map_player_y]
		[game->data->map_player_x] == 'E')
	{
		if (game->data->tot_collectables == game->data->nr_carrot)
			free_and_exit(game, "You won!", EXIT_SUCCESS);
	}
}
