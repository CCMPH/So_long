/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:33:16 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/08 14:33:18 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(dst);
	if (len < dstsize)
		ft_strlcpy(dst + len, (char *)src, dstsize - len);
	else
		return (ft_strlen(src) + dstsize);
	len = len + ft_strlen(src);
	return (len);
}
