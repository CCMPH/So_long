/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_mlx.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 15:25:12 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 11:51:07 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_ground(t_data *data)
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
			index = mlx_image_to_window(data->mlx, data->ground_img,
					x * BLOCKSIZE, y * BLOCKSIZE);
			if (index == -1)
				free_and_exit(data, "Error\nImage to window went wrong",
					EXIT_FAILURE);
			data->ground_img->instances[index].z = 1;
			x++;
		}
		y++;
	}
}

void	set_tree(t_data *data)
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
			if (data->map[y][x] == '1')
			{
				index = mlx_image_to_window(data->mlx, data->tree_img,
						x * BLOCKSIZE, y * BLOCKSIZE);
				if (index == -1)
					free_and_exit(data, "Error\nImage to window went wrong",
						EXIT_FAILURE);
				data->tree_img->instances[index].z = 2;
			}
			x++;
		}
		y++;
	}
}

void	set_rabbit(t_data *data)
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
			if (data->map[y][x] == 'P')
			{
				data->map_player_x = x;
				data->map_player_y = y;
				index = mlx_image_to_window(data->mlx, data->rabbit_img,
						x * BLOCKSIZE, y * BLOCKSIZE);
				if (index == -1)
					free_and_exit(data, "Error\nImage to window went wrong",
						EXIT_FAILURE);
				data->rabbit_img->instances[index].z = 5;
			}
			x++;
		}
		y++;
	}
}

void	set_carrot(t_data *data)
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
			if (data->map[y][x] == 'C')
			{
				index = mlx_image_to_window(data->mlx, data->carrot_img,
						x * BLOCKSIZE, y * BLOCKSIZE);
				if (index == -1)
					free_and_exit(data, "Error\nImage to window went wrong",
						EXIT_FAILURE);
				data->carrot_img->instances[index].z = 3;
			}
			x++;
		}
		y++;
	}
}

void	set_exit(t_data *data)
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
				index = mlx_image_to_window(data->mlx, data->exit_img,
						x * BLOCKSIZE, y * BLOCKSIZE);
				if (index == -1)
					free_and_exit(data, "Error\nImage to window went wrong",
						EXIT_FAILURE);
				data->exit_img->instances[index].z = 4;
			}
			x++;
		}
		y++;
	}
}
