/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
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
		ft_putchar((nb + 48));
}

void 	ft_process_d(t_flags *flags, va_list ap)
{
	long 	d;

	d = va_arg(ap, int);
	if (d < 0)
	{
		d *= -1;
		ft_putchar('-');
		flags->strlen = nblength(d);
		flags->strlen++;
	}
	else
		flags->strlen = nblength(d);
	if (d == 0 && flags->is_prec)
		flags->strlen = 0;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	if (flags->minus == 0)
	{
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		fill_space(flags->zero_filler, '0');
		ft_putnbr(d);
	}
	else if (flags->minus == 1)
	{
		fill_space(flags->zero_filler, '0');
		ft_putnbr(d);
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		
	}
}






