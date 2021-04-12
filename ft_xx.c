/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Xx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:36:03 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/29 14:36:08 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_process_xx(t_flags *flags, va_list ap)
{
	unsigned int 	xx;

	flags->i++;
	xx = va_arg(ap, unsigned int);
	flags->strlen = nbhexlength(xx);
	if (xx == 0 && flags->is_prec)
		flags->strlen = 0;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	else
		flags->zero_filler = 0;
	if (flags->is_prec && flags->minus == 0)
	{
		if (xx == 0 && flags->width == 0 && flags->precision == 0)
			return ;
		if (xx == 0 && flags->width != 0 && flags->precision == 0 )
		{
			fill_space(flags->width, ' ');
			return ;
		}
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		fill_space(flags->zero_filler, '0');
		ft_putnbr_base(xx, "0123456789ABCDEF");
	}
	else if (flags->is_prec && flags->minus == 1)
	{
		if (xx == 0 && flags->width != 0 && flags->precision == 0 )
		{
			fill_space(flags->width, ' ');
			return ;
		}
		fill_space(flags->zero_filler, '0');
		ft_putnbr_base(xx, "0123456789ABCDEF");
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	}
	else if (flags->is_prec == 0 && flags->minus == 0)
	{
		if (flags->zero == 1)
		{
			if (flags->width)
				flags->zero_filler = flags->width - flags->strlen;
			fill_space(flags->zero_filler, '0');
			if (xx == 0)
				ft_flush_char('0');
			ft_putnbr_base(xx, "0123456789ABCDEF");
		}
		else
		{
			fill_space((flags->width - flags->strlen), ' ');
			if (xx == 0)
				ft_flush_char('0');
			ft_putnbr_base(xx, "0123456789ABCDEF");
		}
	}
	else if (flags->is_prec == 0 && flags->minus == 1)
	{
		ft_putnbr_base(xx, "0123456789ABCDEF");
		if (xx == 0)
				ft_flush_char('0');
		fill_space((flags->width - flags->strlen), ' ');
	}
}