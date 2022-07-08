/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 10:37:39 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/08 15:13:57 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	check_values(t_data *data)
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

void	check_border(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		if (data->map[i][0] != '1' || data->map[i][data->columns - 1] != '1')
			exit_msg("Error\nMap isn't surrounded by walls");
		i++;
	}
	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] != '1' || data->map[data->rows - 1][i] != '1')
			exit_msg("Error\nMap isn't surrounded by walls");
		i++;
	}
}

void	check_rectangular(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != data->columns)
			exit_msg("Error\nMap is not rectangular");
		i++;
	}
}

void	check_collected_data(t_data *data)
{
	if (data->exits == 0)
		exit_msg("Error\nMap must have at least 1 exit");
	if (data->collectables == 0)
		exit_msg("Error\nMap must have at least 1 collectable");
	if (data->players == 0)
		exit_msg("Error\nMap doesn't have enough players");
	if (data->players > 1)
		exit_msg("Error\nMap has too many players");
	// if (data->rows == 0 || data->columns == 0)
	// 	exit_msg("Error\nMap is not correct formated");
}

void	check_map(t_data *data)
{
	get_row_and_column(data);
	check_values(data);
	check_rectangular(data);
	check_border(data);
	check_collected_data(data);
}
