/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_movement.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:09:20 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 11:52:02 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	find_location_carrot(t_data	*data)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;
	int	index;

	y = 1;
	index = 0;
	player_x = data->map_player_x;
	player_y = data->map_player_y;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			if (x == player_x && y == player_y)
				return (index);
			if (data->map[y][x] == 'C' || data->map[y][x] == 'K')
				index++;
			x++;
		}
		y++;
	}
	return (index);
}

static void	remove_collectable(t_data *data)
{
	int	index;

	index = find_location_carrot(data);
	data->carrot_img->instances[index].z = -1;
}

static void	set_new_exit(t_data	*data)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map[y][x] == 'E')
			{
				index = mlx_image_to_window(data->mlx, data->exit2_img,
						x * BLOCKSIZE, y * BLOCKSIZE);
				if (index == -1)
					free_and_exit(data, "ERROR", EXIT_FAILURE);
				data->exit2_img->instances[index].z = 4;
			}
			x++;
		}
		y++;
	}
}

static void	edit_exit(t_data *data)
{
	mlx_delete_image(data->mlx, data->exit_img);
	set_new_exit(data);
}

void	set_movement(t_data *data, t_direction direction)
{
	if (direction == UP)
		data->map_player_y--;
	else if (direction == DOWN)
		data->map_player_y++;
	else if (direction == LEFT)
		data->map_player_x--;
	else if (direction == RIGHT)
		data->map_player_x++;
	if (data->map[data->map_player_y][data->map_player_x] == 'C')
	{
		data->nr_carrot++;
		data->map[data->map_player_y][data->map_player_x] = 'K';
		remove_collectable(data);
		if (data->nr_carrot == data->tot_collectables)
			edit_exit(data);
	}
	if (data->map[data->map_player_y][data->map_player_x] == 'E')
	{
		if (data->tot_collectables == data->nr_carrot)
			free_and_exit(data, "You won!", EXIT_SUCCESS);
	}
}
