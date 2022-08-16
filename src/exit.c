/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/10 09:13:59 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 11:40:55 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_msg(char *message)
{
	ft_putendl_fd(message, 1);
	exit(1);
}

static void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_and_exit(t_data *data, char *message, int exit_code)
{
	if (data->map)
		free_map(data);
	ft_putendl_fd(message, 1);
	exit(exit_code);
}

void	free_and_exit_cross(void *param)
{
	t_data	*data;

	data = param;
	if (data->map)
		free_map(data);
	ft_putendl_fd("Game closed", 1);
	exit(EXIT_SUCCESS);
}
