/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:33:02 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/08 14:33:03 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*nstr;
	unsigned int	len;

	len = ft_strlen(s1) + 1;
	nstr = malloc(len * sizeof(char));
	if (nstr == NULL)
		return (nstr);
	ft_memcpy(nstr, s1, len);
	return (nstr);
}
