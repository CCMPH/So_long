/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_mlx.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 15:25:12 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/18 13:46:59 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	set_ground(t_game *game)
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
			//x = x * BLOCKSIZE;
			//y = y * BLOCKSIZE;
			index = mlx_image_to_window(game->mlx, game->data->ground_img, x * BLOCKSIZE, y * BLOCKSIZE);
			//x = x / BLOCKSIZE;
			//y = y / BLOCKSIZE;
			game->data->ground_img->instances[index].z = 1;
			x++;
		}
		y++;
	}
}

void	set_tree(t_game *game)
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
			if (game->data->map[y][x] == '1')
			{
				index = mlx_image_to_window(game->mlx, game->data->tree_img, x * BLOCKSIZE, y * BLOCKSIZE);
				game->data->tree_img->instances[index].z = 2;
			}
			x++;
		}
		y++;
	}
}

void	set_rabbit(t_game *game)
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
			if (game->data->map[y][x] == 'P')
			{
				game->data->map_player_x = x;
				game->data->map_player_y = y;
				index = mlx_image_to_window(game->mlx, game->data->rabbit_img, x * BLOCKSIZE, y * BLOCKSIZE);
				game->data->rabbit_img->instances[index].z = 5;
			}
			x++;
		}
		y++;
	}
}

void	set_carrot(t_game *game)
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
			if (game->data->map[y][x] == 'C')
			{
				game->data->tot_collectables++;
				index = mlx_image_to_window(game->mlx, game->data->carrot_img, x * BLOCKSIZE, y * BLOCKSIZE);
				game->data->carrot_img->instances[index].z = 3;
			}
			x++;
		}
		y++;
	}
}

void	set_exit(t_game *game)
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
				index = mlx_image_to_window(game->mlx, game->data->exit_img, x * BLOCKSIZE, y * BLOCKSIZE);
				game->data->exit_img->instances[index].z = 4;
			}
			x++;
		}
		y++;
	}
}
