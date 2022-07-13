/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 15:27:46 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/13 15:28:26 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	set_textures(t_game *game)
{
	game->data->ground_tex = mlx_load_png("img/Grass.png");
	game->data->tree_tex = mlx_load_png("img/Bush.png");
	game->data->rabbit_tex = mlx_load_png("img/Rabbit.png");
	game->data->carrot_tex = mlx_load_png("img/Carrot2.png");
	game->data->exit_tex = mlx_load_png("img/House.png");
}

void	set_images(t_game *g)
{
	g->data->ground_img = mlx_texture_to_image(g->mlx, g->data->ground_tex);
	g->data->tree_img = mlx_texture_to_image(g->mlx, g->data->tree_tex);
	g->data->rabbit_img = mlx_texture_to_image(g->mlx, g->data->rabbit_tex);
	g->data->carrot_img = mlx_texture_to_image(g->mlx, g->data->carrot_tex);
	g->data->exit_img = mlx_texture_to_image(g->mlx, g->data->exit_tex);
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
