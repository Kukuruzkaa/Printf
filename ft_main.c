#include "ft_printf.h"

int		main()
{
	int	a;
	int	b;

	a = printf("%p\n", (void*)30);
	b = ft_printf("%p\n", (void*)30);
	printf("a = %u\nb = %u\n", a, b);
	return 0;
}