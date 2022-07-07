/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 11:21:57 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/07 15:24:35 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h> //nodig voor printf
#include <fcntl.h> //nodig voor open

void	exit_msg(char *message)
{
	printf("%s\n", message);
	exit(1);
}

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->collectables = 0;
	data->exits = 0;
	data->players = 0;
	data->map_height = 0;
	data->map_width = 0;
}

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

char	**parse_map(int fd)
{
	char	*string;
	char	*tmp_string;
	char	**map;
	int		i;

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
	map = ft_split(string, '\n');
	free(string);
	//printf("%s\n", map[0]);
	i = 0;
	while (map[i] != '\0')
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (map);
}

void	check_values(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
			&& data->map[i][j] != 'C' && data->map[i][j] != 'E'
			&& data->map[i][j] != 'P')
				exit_msg("Error\nInvalid character used in map");
			if (data->map[i][j] == 'C')
				data->collectables++;
			if (data->map[i][j] == 'E')
				data->exits++;
			if (data->map[i][j] == 'P')
				data->players++;
			j++;
		}
		i++;
	}
}

void	get_size_map(t_data *data)
{
	while (data->map[data->map_height] != NULL)
		data->map_height += 1;
	data->map_width = ft_strlen(data->map[0]);
}

void	check_map(t_data *data)
{
	get_size_map(data);
	check_values(data);
	// HIER MORGEN VERDERRR!!
	// check_border
	// check_rectangle
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		exit_msg("Error\nNot enough arguments");
	if (ac > 2)
		exit_msg("Error\nTo many arguments");
	init_struct(&data);
	validate_map(av[1], &data);
	return (0);
}
