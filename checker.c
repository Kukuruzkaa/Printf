/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:52:08 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/20 14:52:21 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = 0;
	flags->minus = 0;
	flags->zero = 0;
	// flags->type;
}

void	get_width(const char *s, t_flags *flags, va_list ap)
{
	while (s[flags->i] && s[flags->i] != '.')
	{
		if (s[flags->i] == '0')
			flags->zero = 1;
		else if (s[flags->i] == '-')
			flags->minus = 1;
		else if (s[flags->i] == '*')
		{
			flags->width = va_arg(ap, int);
		}
		else if (ft_isdigit(s[flags->i]))
		{
			flags->width = (flags->width * 10) + s[flags->i] - '0';
		}
		flags->i++;
	}
}

void	get_precision(const char *s, t_flags *flags, va_list ap)
{
	while (s[flags->i])
	{
		if (s[flags->i] == '.')
		{
			flags->i++;
			if (s[flags->i] == '*')
			{
				flags->precision = va_arg(ap, int);	
			}
			else if (ft_isdigit(s[flags->i]))
			{
				flags->precision = (flags->precision * 10) + s[flags->i] - '0';
			}
		}
		flags->i++;
	}
}

// void	get_flags(const char *s, t_flags *flags)
// {
// 	while (s[flags->i])
// 	{
// 		if (s[flags->i] == '0')
// 			flags->zero = 1;
// 		else if (s[flags->i] == '-')
// 			flags->minus = 1;
// 		flags->i++;
// 	}
// }

void 	check_fmt(const char *s, t_flags *flags)
{
	int i;
	va_list ap;

	init_flags(flags);

	// parser()
	// get_flags(s, flags);
	get_width(s, flags, ap);
	printf(" zero: %d\n", flags->zero);
	printf(" minus : %d\n", flags->minus);
	printf(" width : %d\n", flags->width);
	get_precision(s, flags, ap);
	printf(" precision : %d\n", flags->precision);
}











// 	// formatter()
// 	if ('d')
// 		process_d() //conversion 
// 	else if ('s')
// 		process_s()





// 	// printer()


	

	


// }