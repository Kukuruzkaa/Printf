#include "ft_printf.h"

int		main()
{
	int	a;
	int	b;

	a = printf("%2d\n", 0);
	b = ft_printf("%2d\n", 0);
	printf("a = %u\nb = %u\n", a, b);
	return 0;
}