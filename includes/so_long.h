/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 14:10:01 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/21 16:37:00 by chartema      ########   odam.nl         */
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
	char			**map;
	//mlx_t			*mlx;
	int				collected;
	int				tot_collectables;
	int				nr_carrot;
	int				exits;
	int				players;
	int				columns;
	int				rows;
	int				map_columns;
	int				map_rows;
	int				moves;

	int				map_player_x;
	int				map_player_y;

	mlx_texture_t	*ground_tex;
	mlx_texture_t	*tree_tex;
	mlx_texture_t	*rabbit_tex;
	mlx_texture_t	*carrot_tex;
	mlx_texture_t	*exit_tex;

	mlx_image_t		*ground_img;
	mlx_image_t		*tree_img;
	mlx_image_t		*rabbit_img;
	mlx_image_t		*carrot_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*count_img;

	t_direction		direction;
}				t_data;

typedef struct s_game
{
	t_data	*data;
	mlx_t	*mlx;
}				t_game;

// UTILS //
void	get_row_and_column(t_data *data);
void	exit_msg(char *message);

// VALIDATION //
int		validate_map(char *map, t_game *game);
char	**parse_map(int fd);
void	check_newlines(char *str);
void	check_extension(char *filename, char *ext);

// CHECK_MAP //
void	check_values(t_data *data);
void	check_border(t_data *data);
void	check_rectangular(t_data *data);
void	check_collected_data(t_data *data);
void	check_map(t_data *data);

// MLX //
void	load_game(t_game *game);
void	set_ground(t_game *game);
void	set_tree(t_game *game);
void	set_rabbit(t_game *game);
void	set_carrot(t_game *game);
void	set_exit(t_game *game);
//void	load_map(t_game *game);

#endif