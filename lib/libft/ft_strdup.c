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
