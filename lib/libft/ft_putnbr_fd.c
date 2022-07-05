#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nr;

	nr = n;
	if (nr < 0)
	{
		write (fd, "-", 1);
		nr = nr * -1;
	}
	if (nr > 9)
	{
		ft_putnbr_fd(nr / 10, fd);
		ft_putchar_fd(nr % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nr + '0', fd);
}
