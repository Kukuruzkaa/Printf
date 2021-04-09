#include "ft_printf.h"

int		main()
{
	int	a;
	int	b;

	a = printf("|%-*.3s|\n", 5, "LYDI");
	b = ft_printf("|%-*.3s|\n", 5, "LYDI");
	// a = ft_printf("%-.i", 0);
	// b = printf("%-.i", 0);
	//printf("daria est trop forte");
	//printf("a = %u\nb = %u\n", a, b);
	//printf("a = %u\n", a);
	return 0;
}