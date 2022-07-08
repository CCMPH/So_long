/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 15:10:53 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/08 15:17:36 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h> //nodig voor printf

void	get_row_and_column(t_data *data)
{
	while (data->map[data->rows] != NULL)
		data->rows += 1;
	data->columns = ft_strlen(data->map[0]);
}

void	exit_msg(char *message)
{
	printf("%s\n", message);
	exit(1);
}
