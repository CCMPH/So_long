/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 15:12:40 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/08 15:17:18 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <fcntl.h> //nodig voor open

int	check_extension(char *filename, char *ext)
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
	return (0);
}

void	check_newlines(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		exit_msg("Error\nMap invalid, map starts with a newline");
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			exit_msg("Error\nMap invalid, to many newlines in a row");
		i++;
	}
}

char	**parse_map(int fd)
{
	char	*string;
	char	*tmp_string;
	char	**map;
	// int		i;

	string = ft_calloc(1, sizeof(char));
	while (1)
	{
		tmp_string = get_next_line(fd);
		if (tmp_string != NULL)
		{
			string = ft_strjoin(string, tmp_string);
			if (string == NULL)
				return (NULL);
			free(tmp_string);
		}
		else
			break ;
	}
	check_newlines(string);
	map = ft_split(string, '\n');
	free(string);
	// i = 0;
	// while (map[i] != '\0')
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	return (map);
}

int	validate_map(char *map, t_data *data)
{
	int	fd;

	check_extension(map, ".ber");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_msg("Error\nInvalid file");
	data->map = parse_map(fd);
	check_map(data);
	close(fd);
	return (0);
}