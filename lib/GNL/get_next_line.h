/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:22:14 by chartema      #+#    #+#                 */
/*   Updated: 2022/07/07 11:58:27 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

int		check_newline(char *storage);
int		ft_strlen2(char *s);
char	*join_storage_and_buff(char *storage, char *buff);
char	*free_line(char *str);
void	*ft_calloc2(size_t count, size_t size);
char	*get_next_line(int fd);

#endif