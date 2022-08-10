/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 15:12:40 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/10 11:31:24 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h> //nodig voor open

void	check_extension(char *filename, char *ext)
{
	size_t	filename_len;
	size_t	ext_len;

	if (!filename)
		exit_msg("Error\nThere is no file name");
	if (!ext)
		exit_msg("Error\nThere is no extension");
	filename_len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	while (ext_len > 0)
	{
		if (filename[filename_len] != ext[ext_len])
			exit_msg("Error\nThe argument given is not a .ber file");
		ext_len--;
		filename_len--;
	}
}

void	check_newlines(char *str, t_game *game)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		free_and_exit(game, "Error\nMap invalid, map starts with a newline",
			EXIT_FAILURE);
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			free_and_exit(game, "Error\nMap invalid, to many newlines in a row",
				EXIT_FAILURE);
		i++;
	}
}

char	**parse_map(int fd, t_game *game)
{
	char	*string;
	char	*tmp_string;
	char	**map;

	string = ft_calloc(1, sizeof(char *));
	while (1)
	{
		tmp_string = get_next_line(fd);
		if (tmp_string != NULL)
		{
			string = strjoin_and_free(string, tmp_string);
			if (string == NULL)
				return (NULL);
			free(tmp_string);
		}
		else
			break ;
	}
	check_newlines(string, game);
	map = ft_split(string, '\n');
	free(string);
	return (map);
}

void	get_width_and_height(t_game	*game)
{
	while (game->data->map[game->data->map_rows] != NULL)
		game->data->map_rows += 1;
	game->data->map_columns = ft_strlen(game->data->map[0]);
}

int	validate_map(char *map, t_game *game)
{
	int	fd;

	check_extension(map, ".ber");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		free_and_exit(game, "Error\nInvalid file", EXIT_FAILURE);
	game->data->map = parse_map(fd, game);
	if (game->data->map[0] == NULL)
		free_and_exit(game, "Error\nEmpty file", EXIT_FAILURE);
	get_width_and_height(game);
	check_map(game->data, game);
	close(fd);
	return (0);
}
