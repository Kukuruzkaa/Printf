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
	flags->star = 0;
}

void 	check_fmt(const char *s)
{
	int i;
	t_flags *flags;
	init_flags(flags);

	// parser()
	get_flags();
	get_width();
	get_prec();

	// formatter()
	if ('d')
		process_d() //conversion 
	else if ('s')
		process_s()





	// printer()




	i = 0;

	while (s[i] in "0 -#") //flags
	{
		if (s[i])
			flags->minus = 1;
		if ()

		i++;
	}

	while (s[i] && ft_isdigit(s[i])) //width 
	{
		flags->width = (flags->width * 10) + s[i] - '0';
		i++;
	}

	if (s[i] == '.')
	{
		i++;
		while (s[i] && ft_isdigit(s[i])) //prec
		{
			flags->precision = (flags->precision * 10) + s[i] - '0';
			i++;
		}
	}


}