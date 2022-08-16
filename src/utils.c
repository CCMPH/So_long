/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 15:10:53 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/16 11:45:07 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*strjoin_and_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char)
			*(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->tot_collectables = 0;
	data->nr_carrot = 0;
	data->exits = 0;
	data->players = 0;
	data->rows = 0;
	data->columns = 0;
	data->map_player_x = 0;
	data->map_player_y = 0;
	data->moves = 0;
}

void	count_move(t_data *data)
{
	char	*move_str;

	move_str = NULL;
	data->moves++;
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
	move_str = ft_itoa(data->moves);
	if (data->count_img)
		mlx_delete_image(data->mlx, data->count_img);
	data->count_img = mlx_put_string(data->mlx, move_str, 0, 0);
	if (!data->count_img)
		free_and_exit(data, "Error\nPrinting string into window went wrong",
			EXIT_FAILURE);
	free(move_str);
	if (!data->count_img)
		exit(0);
}

void	get_row_and_column(t_data *data)
{
	while (data->map[data->rows] != NULL)
		data->rows += 1;
	data->columns = ft_strlen(data->map[0]);
}
