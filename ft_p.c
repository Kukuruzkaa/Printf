/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:06:25 by ddiakova          #+#    #+#             */
/*   Updated: 2021/04/02 16:06:30 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nblength(uintptr_t n)
{
	int 		l;

	l = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		l++;
	}
	return (l);
}

static void	ft_putnbr_base(uintptr_t n, char *base)
{
	int 			i;
	char 			c;

	i = 0;
	while (base[i])
		i++;
	if (n > 0)
	{
		c = base[n % i];
		ft_putnbr_base(n/i, base);
		ft_flush_char(c);
	}
}

void 	ft_process_p(t_flags *flags, va_list ap)
{
	void *p;
	uintptr_t n;
	flags->i++;
	p = va_arg(ap, void*);
	n = (uintptr_t)p;
	flags->strlen = nblength(n) + 2;
	if (p == 0 && flags->is_prec)
		flags->strlen = 0;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	else
		flags->zero_filler = 0;
	if (flags->is_prec && flags->minus == 0)
	{
		if (p == 0 && flags->width == 0 && flags->precision == 0)
		{
			ft_putstr("0x", 2);
			return ;
		}
		if (p == 0 && flags->width != 0 && flags->precision == 0 )
		{
			fill_space(flags->width - 2, ' ');
			ft_putstr("0x", 2);
			return ;
		}
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		ft_putstr("0x", 2);
		fill_space(flags->zero_filler, '0');
		ft_putnbr_base(n, "0123456789abcdef");
	}
	else if (flags->is_prec && flags->minus == 1)
	{
		if (p == 0 && flags->width != 0 && flags->precision == 0 )
		{
			fill_space(flags->width, ' ');
			return ;
		}
		fill_space(flags->zero_filler, '0');
		ft_putstr("0x", 2);
		ft_putnbr_base(n, "0123456789abcdef");
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	}
	else if (flags->is_prec == 0 && flags->minus == 0)
	{
		if (flags->zero == 1)
		{
			if (flags->width)
				flags->zero_filler = flags->width - flags->strlen;
			fill_space(flags->zero_filler, '0');
			if (p == 0)
				ft_flush_char('0');
			ft_putstr("0x", 2);
			ft_putnbr_base(n, "0123456789abcdef");
		}
		else
		{
			fill_space((flags->width - flags->strlen), ' ');
			ft_putstr("0x", 2);
			if (p == 0)
				ft_flush_char('0');
			ft_putnbr_base(n, "0123456789abcdef");
		}
	}
	else if (flags->is_prec == 0 && flags->minus == 1)
	{
		ft_putstr("0x", 2);
		ft_putnbr_base(n, "0123456789abcdef");
		if (p == 0)
				ft_flush_char('0');
		fill_space((flags->width - flags->strlen), ' ');
	}
}