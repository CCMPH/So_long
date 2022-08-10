/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:33:46 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/08 14:33:47 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*str;

	if (!s1)
		return (NULL);
	begin = 0;
	while (s1[begin] != '\0' && ft_contains(set, s1[begin]))
		begin++;
	end = ft_strlen(s1) - 1;
	if (s1[begin] == 0)
		return (ft_strdup(""));
	while (ft_contains(set, s1[end]))
		end--;
	str = malloc((end - begin + 2) * sizeof(*s1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + begin, end - begin + 1);
	str[end - begin + 1] = '\0';
	return (str);
}
