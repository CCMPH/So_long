/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 11:21:57 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/08 15:17:28 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->collectables = 0;
	data->exits = 0;
	data->players = 0;
	data->rows = 0;
	data->columns = 0;
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
