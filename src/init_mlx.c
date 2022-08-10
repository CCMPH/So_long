/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 15:27:46 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/10 12:23:14 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// MOET IK DEZE MLX - FUNTIES OOK PROTECTEN?
void	set_textures(t_game *game)
{
	game->data->ground_tex = mlx_load_png("img/Grass.png");
	game->data->tree_tex = mlx_load_png("img/Bush.png");
	game->data->rabbit_tex = mlx_load_png("img/Rabbit.png");
	game->data->carrot_tex = mlx_load_png("img/Carrot2.png");
	game->data->exit_tex = mlx_load_png("img/House.png");
	game->data->exit2_tex = mlx_load_png("img/House_open.png");
	if (!game->data->ground_tex || !game->data->tree_tex
		|| !game->data->rabbit_tex || !game->data->carrot_tex
		|| !game->data->exit_tex || !game->data->exit2_tex)
		free_and_exit(game, "Error\nLoad pgn file went wrong", EXIT_FAILURE);
}

void	set_images(t_game *g)
{
	g->data->ground_img = mlx_texture_to_image(g->mlx, g->data->ground_tex);
	g->data->tree_img = mlx_texture_to_image(g->mlx, g->data->tree_tex);
	g->data->rabbit_img = mlx_texture_to_image(g->mlx, g->data->rabbit_tex);
	g->data->carrot_img = mlx_texture_to_image(g->mlx, g->data->carrot_tex);
	g->data->exit_img = mlx_texture_to_image(g->mlx, g->data->exit_tex);
	g->data->exit2_img = mlx_texture_to_image(g->mlx, g->data->exit2_tex);
	if (!g->data->ground_img || !g->data->tree_img || !g->data->rabbit_img
		|| !g->data->carrot_img || !g->data->exit_img || !g->data->exit2_img)
		free_and_exit(g, "Error\nConvert texture to image went wrong",
			EXIT_FAILURE);
}

void	load_map(t_game *game)
{
	set_ground(game);
	set_tree(game);
	set_rabbit(game);
	set_carrot(game);
	set_exit(game);
}

void	load_game(t_game *game)
{
	set_textures(game);
	set_images(game);
	load_map(game);
}
