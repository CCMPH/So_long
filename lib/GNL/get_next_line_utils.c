/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 14:18:59 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/09 11:17:10 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	check_newline(char *storage)
{
	int	i;

	i = 0;
	if (!storage)
		return (0);
	while (storage[i] != '\0')
	{
		if (storage[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*free_line(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

void	*ft_calloc2(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*join_storage_and_buff(char *storage, char *buff)
{
	int		i;
	int		j;
	char	*str;

	str = ft_calloc2((ft_strlen2(storage)
				+ ft_strlen2(buff) + 1), sizeof(char));
	if (!str)
		return (free_line(storage));
	i = 0;
	j = 0;
	while (storage[i] != '\0')
	{
		str[i] = storage[i];
		i++;
	}
	while (buff[j] != '\0')
	{	
		str[i + j] = buff[j];
		j++;
	}
	free(storage);
	return (str);
}
