/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:57:08 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/20 11:57:24 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char*	concatinate(int n, ...)
// {
// 	char *str;

// 	str = strdup("");
// 	va_list args;
// 	va_start(args, n);

// 	for (int i = 0; i < n; i++)
// 	{
// 		str = strcat(str, va_arg(args, char*));
// 	}
// 	va_end(args);
// 	return str;
// }

int		ft_printf(const char *fmt, ...)
{
	t_flags flags;
	va_list args;
	va_start(args, fmt);
	//int i;

	flags.i = 0;
	
	while (fmt[flags.i] != '\0')
	{
		if (fmt[flags.i] == '%')
		{
			flags.i++;
			check_fmt(fmt, &flags);


			if (fmt[flags.i] == 'd')
				ft_process_di(&flags, args);
			// if (fmt[flags.i] == 's')
			// 	ft_process_s(&flags, args);
			// {	
			// 	i++;
			// 	printf("%s", va_arg(args, char*));
			// }
			// if (fmt[flags.i] == 'c')
			// 	ft_process_c(&flags, args);
			// {	
			// 	i++;
			// 	printf("%c", va_arg(args, int));
		}
		else
		{
			ft_putchar(fmt[flags.i]);
			//printf("%s\n", "hola");
		}
		flags.i++;
	}
	va_end(args);
	return 1;
}




int		main()
{
	ft_printf("qqqqq : %030.10d\n", 10);
	printf("qqqqq : %030.10d\n", 10);
	return 0;
}