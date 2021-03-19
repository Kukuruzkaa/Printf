#include <string.h>
#include <stdio.h>
#include <stdarg.h>


char*	concatinate(int n, ...)
{
	char *str;

	str = strdup("");
	va_list args;
	va_start(args, n);

	for (int i = 0; i < n; i++)
	{
		str = strcat(str, va_arg(args, char*));
	}
	va_end(args);
	return str;
}

int		myprint(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	
	for (int i = 0; i < strlen(fmt); i++)
	{
		if (fmt[i] == '%' && strlen(fmt) - 1 != i && fmt[i+1] == 'd')
		{
			i++;
			printf("%d", va_arg(args, int));
		}
		else if (fmt[i] == '%' && strlen(fmt) - 1 != i && fmt[i+1] == 's')
		{	
			i++;
			printf("%s", va_arg(args, char*));
		}
		else if (fmt[i] == '%' && strlen(fmt) - 1 != i && fmt[i+1] == 'c')
		{	
			i++;
			printf("%c", va_arg(args, int));
		}
		else
			putchar(fmt[i]);
	}
	va_end(args);
	return 1;
}









int		main()
{
	myprint("qqqqq : %suuu%du\n%", concatinate(4, strdup("abc"), strdup("efg"), strdup("hig"), strdup("klm"))
	         ,42);
	return 0;
}
