
void	ft_putnbr(int nb, char *base)
{
	long n;

	int i;

	i = 0;
	while (base[i])
		i++;
	n = nb;
	if(ft_checking_base(base))
		return ;
	if (n < 0)
	{ 
		n *= -1;
		write(1, "-", 1);
	}
	if (n == 0)
		write(1, "0", 1);
	else
		ft_myprint(n, base, i);
}

void ft_myprint(long n, char *base, int count)
{
	char c;

	if (n > 0)
	{
		c = base[n % i];
		ft_myprint(n/i, base, i);
		write(1, &c, 1);
	}
}

unsigned int	nbr;

	flags->i++;
	nbr = va_arg(flags->arg, unsigned int);
	flags->len = _longlen_base(nbr, 16);
	if (nbr == 0 && flags->have_precision)
		flags->len = 0;
	if (flags->have_precision && flags->precision > flags->len)
		flags->zero_count = flags->precision - flags->len;
	_print_x_char(flags->width - (flags->zero_count + flags->len), ' ', &flags);
	_print_x_char(flags->zero_count, '0', &flags);
	if (flags->have_precision && nbr == 0)
		return ;
	_putnbr_base(nbr, 16, "0123456789abcdef");
	flags->output += flags->len;
}