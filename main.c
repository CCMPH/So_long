/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 11:21:57 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/05 16:13:56 by chartema      ########   odam.nl         */
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

// void	init_struct(t_game_date *gd)
// {
// 	//Nog mee verder
// }

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
			exit_msg("Error\nWrong file extension used");
		ext_len--;
		filename_len--;
	}
	return (0);
}

int	parse_map(char *map, t_game_data *gd)
{
	//
}


int	validate_map(char *map, t_game_data *gd)
{
	//int	fd;
	(void)gd;

	// fd = open(map, O_RDONLY);
	// if (fd == -1)
	// 	exit_msg("Error\nInvalid file");
	check_extension(map, ".ber");
	//parse_map(map, &gd);
	//close(fd);
	//check_map
	return (0);
}

int	main(int ac, char **av)
{
	t_game_data	game_data;

	if (ac == 1)
		exit_msg("Error\nNot enough arguments");
	if (ac > 2)
		exit_msg("Error\nTo many arguments");
	//init_struct(&game_data);
	validate_map(av[1], &game_data);
	return (0);
}
