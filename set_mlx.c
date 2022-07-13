/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_mlx.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 15:25:12 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/13 15:26:19 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	set_ground(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->data->map_rows)
	{
		x = 0;
		while (x < game->data->map_columns)
		{
			//x = x * BLOCKSIZE;
			//y = y * BLOCKSIZE;
			mlx_image_to_window(game->mlx, game->data->ground_img, x * BLOCKSIZE, y * BLOCKSIZE);
			//x = x / BLOCKSIZE;
			//y = y / BLOCKSIZE;
			x++;
		}
		y++;
	}
}

void	set_tree(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->data->map_rows)
	{
		x = 0;
		while (x < game->data->map_columns)
		{
			if (game->data->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->data->tree_img, x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		y++;
	}
}

void	set_rabbit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->data->map_rows)
	{
		x = 0;
		while (x < game->data->map_columns)
		{
			if (game->data->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->data->rabbit_img, x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		y++;
	}
}

void	set_carrot(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->data->map_rows)
	{
		x = 0;
		while (x < game->data->map_columns)
		{
			if (game->data->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->data->carrot_img, x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		y++;
	}
}

void	set_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->data->map_rows)
	{
		x = 0;
		while (x < game->data->map_columns)
		{
			if (game->data->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->data->exit_img, x * BLOCKSIZE, y * BLOCKSIZE);
			x++;
		}
		y++;
	}
}
