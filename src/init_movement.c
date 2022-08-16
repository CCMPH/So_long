/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_movement.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:03:31 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 11:16:39 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_movement_valid(t_data *data, t_direction direction)
{
	int	x;
	int	y;

	x = data->rabbit_img->instances->x / BLOCKSIZE;
	y = data->rabbit_img->instances->y / BLOCKSIZE;
	if (direction == UP && data->map[y - 1][x] == '1')
		return (0);
	if (direction == DOWN && data->map[y + 1][x] == '1')
		return (0);
	if (direction == LEFT && data->map[y][x - 1] == '1')
		return (0);
	if (direction == RIGHT && data->map[y][x + 1] == '1')
		return (0);
	return (1);
}

static void	move_player(t_data *data, char direction)
{
	if (direction == UP)
		data->rabbit_img->instances->y -= BLOCKSIZE;
	if (direction == DOWN)
		data->rabbit_img->instances->y += BLOCKSIZE;
	if (direction == LEFT)
		data->rabbit_img->instances->x -= BLOCKSIZE;
	if (direction == RIGHT)
		data->rabbit_img->instances->x += BLOCKSIZE;
	count_move(data);
}

void	init_movement(t_data *data, t_direction direction)
{
	if (check_movement_valid(data, direction))
	{
		move_player(data, direction);
		set_movement(data, direction);
	}
}
