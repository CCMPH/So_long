/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:32:27 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/08 14:32:28 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int		i;
	unsigned char		*dest;
	unsigned const char	*str;

	i = 0;
	dest = dst;
	str = src;
	if (str == 0 && dest == 0)
		return (NULL);
	if (dest < str)
		ft_memcpy(dest, str, len);
	else
	{
		while (len > 0)
		{
			dest[i + (len - 1)] = str[i + (len - 1)];
			len--;
		}
	}
	return (dst);
}
