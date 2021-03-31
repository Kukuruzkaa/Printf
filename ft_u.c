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

int	nblength(long nb)
{
	int 	l;

	l = 0;
	if (nb == 0)
		return (1);
	while (nb > 0 && nb <=255)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

void	ft_putnbr(int n)
{
	int	nb;

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

	u = va_arg(ap, unsigned int);
	flags->strlen = nblength(u);
	if (u == 0 && flags->is_prec)
		flags->strlen = 1;
	if (flags->is_prec && flags->precision > flags->strlen)
		flags->zero_filler = flags->precision - flags->strlen;
	if (flags->minus == 0)
	{
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		fill_space(flags->zero_filler, '0');
		ft_putnbr(u);
	}
	else if (flags->minus == 1)
	{
		fill_space(flags->zero_filler, '0');
		ft_putnbr(u);
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	}
}
