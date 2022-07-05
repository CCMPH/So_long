#include "libft.h"

static int	length(long nr)
{
	int	len;

	len = 0;
	if (nr == 0)
		return (1);
	if (nr < 0)
		len++;
	while (nr != 0)
	{
		nr = nr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nr;

	nr = n;
	len = length(nr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nr == 0)
		str[0] = '0';
	else if (nr < 0)
	{
		str[0] = '-';
		nr = nr * -1;
	}
	while (nr > 0)
	{
		len--;
		str[len] = '0' + (nr % 10);
		nr = nr / 10;
	}
	return (str);
}
