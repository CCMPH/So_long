/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 10:37:39 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/10 11:21:20 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_values(t_data *data, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
			&& data->map[i][j] != 'C' && data->map[i][j] != 'E'
			&& data->map[i][j] != 'P')
				free_and_exit(game, "Error\nInvalid character used in map",
					EXIT_FAILURE);
			if (data->map[i][j] == 'C')
				data->collected++;
			if (data->map[i][j] == 'E')
				data->exits++;
			if (data->map[i][j] == 'P')
				data->players++;
			j++;
		}
		i++;
	}
}

void	check_border(t_data *data, t_game *game)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		if (data->map[i][0] != '1' || data->map[i][data->columns - 1] != '1')
			free_and_exit(game, "Error\nMap isn't surrounded by walls",
				EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] != '1' || data->map[data->rows - 1][i] != '1')
			free_and_exit(game, "Error\nMap isn't surrounded by walls",
				EXIT_FAILURE);
		i++;
	}
}

void	check_rectangular(t_data *data, t_game *game)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != data->columns)
			free_and_exit(game, "Error\nMap is not rectangular", EXIT_FAILURE);
		i++;
	}
}

void	check_collected_data(t_data *data, t_game *game)
{
	if (data->exits == 0)
		free_and_exit(game, "Error\nMap must have at least 1 exit",
			EXIT_FAILURE);
	if (data->collected == 0)
		free_and_exit(game, "Error\nMap must have at least 1 collectable",
			EXIT_FAILURE);
	if (data->players == 0)
		free_and_exit(game, "Error\nMap doesn't have enough players",
			EXIT_FAILURE);
	if (data->players > 1)
		free_and_exit(game, "Error\nMap has too many players", EXIT_FAILURE);
}

void	check_map(t_data *data, t_game *game)
{
	get_row_and_column(data);
	check_values(data, game);
	check_rectangular(data, game);
	check_border(data, game);
	check_collected_data(data, game);
}
