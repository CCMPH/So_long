#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	x;

	str = (unsigned char *)s;
	x = (unsigned char)c;
	while (n > 0)
	{
		if (*str == x)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
