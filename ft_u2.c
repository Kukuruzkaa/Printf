#include "ft_printf.h"


static void 	ft_zerofilling(t_flags *flags, unsigned int n)
{
	fill_space(flags->zero_filler, '0');
	ft_putnbr(n);
}

static void 	ft_if_prec(t_flags *flags, unsigned int n)
{
	if (flags->is_prec && flags->minus == 0)
	{
		if (n == 0 && flags->width == 0 && flags->precision == 0)
			return ;
		if (n == 0 && flags->width != 0 && flags->precision == 0 )
		{
			fill_space(flags->width, ' ');
			return ;
		}
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
		ft_zerofilling(flags, n);
	}
	else if (flags->is_prec && flags->minus == 1)
	{
		if (n == 0 && flags->width != 0 && flags->precision == 0 )
		{
			fill_space(flags->width, ' ');
			return ;
		}
		else if (n == 0 && flags->width == 0 && flags->precision == 0 )
		{
			fill_space(flags->zero_filler, '0');
			return ;
		}
		ft_zerofilling(flags, n);
		fill_space(flags->width - (flags->zero_filler + flags->strlen), ' ');
	}
}

static void 	ft_if_zeroprec(t_flags *flags, unsigned int n)
{
	if (flags->minus == 0 && flags->is_prec == 0)
	{
		if (flags->zero == 1)
		{
			if (flags->width)
				flags->zero_filler = flags->width - flags->strlen;
			ft_zerofilling(flags, n);
		}
		else 
		{
			fill_space((flags->width - flags->strlen), ' ');
			ft_putnbr(n);
		}
	}
	else if (flags->minus == 1 && flags->is_prec == 0)
	{
		ft_putnbr(n);
		fill_space((flags->width - flags->strlen), ' ');
	}
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
	ft_if_prec(flags, u);
	ft_if_zeroprec(flags, u);
}