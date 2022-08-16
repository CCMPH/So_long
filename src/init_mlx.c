/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 15:27:46 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 11:15:31 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_textures(t_data *data)
{
	data->ground_tex = mlx_load_png("img/Grass.png");
	data->tree_tex = mlx_load_png("img/Bush.png");
	data->rabbit_tex = mlx_load_png("img/Rabbit.png");
	data->carrot_tex = mlx_load_png("img/Carrot.png");
	data->exit_tex = mlx_load_png("img/House.png");
	data->exit2_tex = mlx_load_png("img/House_open.png");
	if (!data->ground_tex || !data->tree_tex || !data->rabbit_tex
		|| !data->carrot_tex || !data->exit_tex || !data->exit2_tex)
		free_and_exit(data, "Error\nLoad pgn file went wrong", EXIT_FAILURE);
}

static void	set_images(t_data *data)
{
	data->ground_img = mlx_texture_to_image(data->mlx, data->ground_tex);
	data->tree_img = mlx_texture_to_image(data->mlx, data->tree_tex);
	data->rabbit_img = mlx_texture_to_image(data->mlx, data->rabbit_tex);
	data->carrot_img = mlx_texture_to_image(data->mlx, data->carrot_tex);
	data->exit_img = mlx_texture_to_image(data->mlx, data->exit_tex);
	data->exit2_img = mlx_texture_to_image(data->mlx, data->exit2_tex);
	if (!data->ground_img || !data->tree_img || !data->rabbit_img
		|| !data->carrot_img || !data->exit_img || !data->exit2_img)
		free_and_exit(data, "Error\nConvert texture to image went wrong",
			EXIT_FAILURE);
}

static void	load_map(t_data *data)
{
	set_ground(data);
	set_tree(data);
	set_rabbit(data);
	set_carrot(data);
	set_exit(data);
}

void	load_game(t_data *data)
{
	set_textures(data);
	set_images(data);
	load_map(data);
}
