/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:03:43 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/27 11:04:02 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nblength(long nb)
{
	int 	l;

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

void	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_flush_char(nb + 48);
}

void 	ft_process_di(t_flags *flags, va_list ap)
{
	long 	di;

	flags->i++;
	di = va_arg(ap, int);
	if (di < 0)
	{
		di *= -1;
		flags->neg_number = 1;
	}
	flags->strlen = nblength(di);
	if (di == 0 && flags->is_prec)
		flags->strlen = 1;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	else
		flags->zero_filler = flags->width - flags->strlen;
	if (flags->neg_number)
		flags->strlen++;
	if (flags->is_prec && flags->minus == 0)
	{
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		if (flags->neg_number)
			ft_flush_char('-');
		fill_space(flags->zero_filler, '0');
		ft_putnbr(di);
	}
	else if (flags->is_prec && flags->minus == 1)
	{
		if (flags->neg_number)
			ft_flush_char('-');
		fill_space(flags->zero_filler, '0');
		ft_putnbr(di);
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	}
	else if (flags->minus == 0 && flags->is_prec == 0)
	{
		if (flags->zero == 1)
		{
			if (flags->neg_number)
				ft_flush_char('-');
			fill_space(flags->zero_filler, '0');
			ft_putnbr(di);
		}
		else 
		{
			fill_space((flags->width - flags->strlen), ' ');
			if (flags->neg_number)
				ft_flush_char('-');
			ft_putnbr(di);
		}
	}
	else if (flags->minus == 1 && flags->is_prec == 0)
	{
		if (flags->neg_number)
			ft_flush_char('-');
		ft_putnbr(di);
		fill_space((flags->width - flags->strlen), ' ');
	}
}