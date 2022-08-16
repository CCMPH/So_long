/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 15:12:40 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 12:04:37 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h> //nodig voor open

static void	check_extension(char *filename, char *ext)
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

static void	check_newlines(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		free_and_exit(data, "Error\nMap invalid, map starts with a newline",
			EXIT_FAILURE);
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			free_and_exit(data, "Error\nMap invalid, to many newlines in a row",
				EXIT_FAILURE);
		i++;
	}
}

static char	**parse_map(int fd, t_data *data)
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
	check_newlines(string, data);
	map = ft_split(string, '\n');
	free(string);
	return (map);
}

int	validate_map(char *map, t_data *data)
{
	int	fd;

	check_extension(map, ".ber");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		free_and_exit(data, "Error\nInvalid file", EXIT_FAILURE);
	data->map = parse_map(fd, data);
	if (data->map == NULL)
		free_and_exit(data, "Error\nInvalid file", EXIT_FAILURE);
	if (data->map[0] == NULL)
		free_and_exit(data, "Error\nEmpty file", EXIT_FAILURE);
	check_map(data);
	close(fd);
	return (0);
}
