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
	va_list args;
	va_start(args, fmt);
	int i;

	i = 0;
	
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			check_fmt(fmt + i + 1, )


			// if (fmt[i+1] == 'd')
			// {
			// 	i++;
			// 	printf("%d", va_arg(args, int));
			// }
			// else if (fmt[i+1] == 's')
			// {	
			// 	i++;
			// 	printf("%s", va_arg(args, char*));
			// }
			// else if (fmt[i+1] == 'c')
			// {	
			// 	i++;
			// 	printf("%c", va_arg(args, int));
		}
		else
			ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	return 1;
}




int		main()
{
	ft_printf("qqqqq : %#0333.25suuu%d\n%", "abc", 42);
	return 0;
}