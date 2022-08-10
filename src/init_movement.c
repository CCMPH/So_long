/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_movement.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:03:31 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/09 10:57:40 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	init_movement(t_game *game, t_direction direction)
{
	if (check_movement_valid(game, direction))
	{
		move_player(game, direction);
		set_movement(game, direction);
	}
}
