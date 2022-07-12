/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 14:10:01 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/12 15:02:35 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BLOCKSIZE 128

# include "../lib/libft/libft.h"
# include "../lib/GNL/get_next_line.h"
# include "MLX42/MLX42.h"

typedef struct s_data
{
	char	**map;
	mlx_t	*mlx;
	int		collectables;
	int		exits;
	int		players;
	int		columns;
	int		rows;

	void	*ground_texture;
	void	*ground_image;
	void	*tree_texture;
	void	*tree_image;
	void	*rabbit_texture;
	void	*rabbit_image;
	void	*player_texture;
	void	*collectable_texture;
	void	*exit_texture;
}				t_data;

// UTILS //
void	get_row_and_column(t_data *data);
void	exit_msg(char *message);

// VALIDATION //
int		validate_map(char *map, t_data *data);
char	**parse_map(int fd);
void	check_newlines(char *str);
int		check_extension(char *filename, char *ext);

// CHECK_MAP //
void	check_values(t_data *data);
void	check_border(t_data *data);
void	check_rectangular(t_data *data);
void	check_collected_data(t_data *data);
void	check_map(t_data *data);

#endif