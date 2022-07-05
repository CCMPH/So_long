#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	if (c == '\0')
		return (ft_strchr(s, c));
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			last = s;
		s++;
	}
	return ((char *)last);
}
