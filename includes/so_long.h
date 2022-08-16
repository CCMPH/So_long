/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 14:10:01 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 12:00:38 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BLOCKSIZE 128

# include "../lib/libft/libft.h"
# include "../lib/GNL/get_next_line.h"
# include "MLX42/MLX42.h"

typedef enum e_direction
{
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4,
}			t_direction;

typedef struct s_data
{
	mlx_t			*mlx;

	char			**map;
	int				tot_collectables;
	int				nr_carrot;
	int				exits;
	int				players;
	int				columns;
	int				rows;
	int				moves;

	int				map_player_x;
	int				map_player_y;

	mlx_texture_t	*ground_tex;
	mlx_texture_t	*tree_tex;
	mlx_texture_t	*rabbit_tex;
	mlx_texture_t	*carrot_tex;
	mlx_texture_t	*exit_tex;
	mlx_texture_t	*exit2_tex;

	mlx_image_t		*ground_img;
	mlx_image_t		*tree_img;
	mlx_image_t		*rabbit_img;
	mlx_image_t		*carrot_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*exit2_img;
	mlx_image_t		*count_img;

	t_direction		direction;
}				t_data;

// UTILS //
char	*strjoin_and_free(char *s1, char *s2);
void	init_struct(t_data *data);
void	count_move(t_data *data);
void	get_row_and_column(t_data *data);

// FREE AND EXIT //
void	exit_msg(char *message);
void	free_and_exit_cross(void *param);
void	free_and_exit(t_data *data, char *message, int exit_code);

// VALIDATION //
int		validate_map(char *map, t_data *data);

// CHECK_MAP //
void	check_map(t_data *data);

// MLX //
void	load_game(t_data *data);
void	set_ground(t_data *data);
void	set_tree(t_data *data);
void	set_rabbit(t_data *data);
void	set_carrot(t_data *data);
void	set_exit(t_data *data);

// MOVEMENT //
void	init_movement(t_data *data, t_direction direction);
void	set_movement(t_data *data, t_direction direction);

#endif