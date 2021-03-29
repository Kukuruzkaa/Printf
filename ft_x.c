/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:36:03 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/29 14:36:08 by ddiakova         ###   ########.fr       */
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
		nb = nb / 16;
		l++;
	}
	return (l);
}

void	ft_putnbr_base(int n, char *base)
{
	unsigned int	nb;
	int 			i;

	i = 0;
	*base = "0123456789abcdef";
	nb = n;
	while (base[i])
		i++;
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putnbr_base(nb % 16, base);
	}
	else
		ft_putchar((nb + 48));
}

void 	ft_process_di(t_flags *flags, va_list ap)
{
	long 	di;

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
	if (flags->neg_number)
		flags->strlen++;
	if (flags->minus == 0)
	{
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		if (flags->neg_number)
			ft_putchar('-');
		fill_space(flags->zero_filler, '0');
		ft_putnbr(di);
	}
	else if (flags->minus == 1)
	{
		if (flags->neg_number)
			ft_putchar('-');
		fill_space(flags->zero_filler, '0');
		ft_putnbr(di);
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	}
}