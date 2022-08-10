/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/10 09:13:59 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/10 13:30:16 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_msg(char *message)
{
	ft_putendl_fd(message, 1);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->data->map_rows)
	{
		free(game->data->map[i]);
		i++;
	}
	free(game->data->map);
}

void	free_and_exit(t_game *game, char *message, int exit_code)
{
	if (game->data->map)
		free_map(game);
	ft_putendl_fd(message, 1);
	exit(exit_code);
}

void	free_and_exit_cross(void *param)
{
	t_game	*game;

	game = param;
	if (game->data->map)
		free_map(game);
	ft_putendl_fd("Game closed", 1);
	exit(EXIT_SUCCESS);
}
