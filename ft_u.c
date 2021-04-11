/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:05:10 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/29 12:05:15 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nblength(long nb)
{
	long 	l;

	l = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

static void	ft_putnbr(long n)
{
	long	nb;

	nb = n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_flush_char((nb + 48));
}

void 	ft_process_u(t_flags *flags, va_list ap)
{
	unsigned int 	u;

	flags->i++;
	u = va_arg(ap, unsigned int);
	flags->strlen = nblength(u);
	if (u == 0 && flags->is_prec)
		flags->strlen = 1;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	else
		flags->zero_filler = 0;
	if (flags->is_prec && flags->minus == 0)
	{
		if (u == 0 && flags->width == 0 && flags->precision == 0)
			return ;
		if (u == 0 && flags->width != 0 && flags->precision == 0 )
		{
			fill_space(flags->width, ' ');
			return ;
		}
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		fill_space(flags->zero_filler, '0');
		ft_putnbr(u);
	}
	else if (flags->is_prec && flags->minus == 1)
	{
		if (u == 0 && flags->width != 0 && flags->precision == 0 )
		{
			fill_space(flags->width, ' ');
			return ;
		}
		else if (u == 0 && flags->width == 0 && flags->precision == 0 )
		{
			fill_space(flags->zero_filler, '0');
			return ;
		}
		fill_space(flags->zero_filler, '0');
		ft_putnbr(u);
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	}
	else if (flags->minus == 0 && flags->is_prec == 0)
	{
		if (flags->zero == 1)
		{
			if (flags->width)
				flags->zero_filler = flags->width - flags->strlen;
			fill_space(flags->zero_filler, '0');
			ft_putnbr(u);
		}
		else 
		{
			fill_space((flags->width - flags->strlen), ' ');
			ft_putnbr(u);
		}
	}
	else if (flags->minus == 1 && flags->is_prec == 0)
	{
		ft_putnbr(u);
		fill_space((flags->width - flags->strlen), ' ');
	}
}
