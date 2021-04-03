/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:31:42 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/26 10:31:51 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_process_s(t_flags *flags, va_list ap)
{
	char	*s;

	flags->i++;
	s = va_arg(ap, char*);
	if (s == NULL)
		s = "(null)";
	flags->strlen = ft_strlen(s);
	if (flags->is_prec && flags->precision < flags->strlen)
		flags->strlen = flags->precision;
	if (flags->minus == 0)
	{
		if (flags->zero == 1)
		{
			fill_space(flags->width - flags->strlen, '0');
			ft_putstr(s, flags->strlen);
		}
		else 
		{
			fill_space(flags->width - flags->strlen, ' ');
			ft_putstr(s, flags->strlen);
		}
	}
	else
	{
		ft_putstr(s, flags->strlen);
		fill_space(flags->width - flags->strlen, ' ');
	}
}

