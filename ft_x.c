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
	char 			c;

	i = 0;
	nb = n;
	while (base[i])
		i++;
	if (n > 0)
	{
		c = base[nb % i];
		ft_putnbr_base(nb/i, base);
		ft_flush_char(c);
	}
}

void 	ft_process_x(t_flags *flags, va_list ap)
{
	unsigned int 	x;

	x = va_arg(ap, unsigned int);
	flags->strlen = nblength(x);
	if (x == 0 && flags->is_prec)
		flags->strlen = 1;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	else
		flags->zero_filler = flags->width - flags->strlen;
	if (flags->is_prec && flags->minus == 0)
	{
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		fill_space(flags->zero_filler, '0');
		ft_putnbr_base(x, "0123456789abcdef");
	}
	else if (flags->is_prec && flags->minus == 1)
	{
		fill_space(flags->zero_filler, '0');
		ft_putnbr_base(x, "0123456789abcdef");
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	}
	else if (flags->is_prec == 0 && flags->minus == 0)
	{
		fill_space(flags->zero_filler, ' ');
		ft_putnbr_base(x, "0123456789abcdef");
	}
	else if (flags->is_prec == 0 && flags->minus == 1)
	{
		ft_putnbr_base(x, "0123456789abcdef");
		fill_space((flags->width - flags->strlen), ' ');
	}
}