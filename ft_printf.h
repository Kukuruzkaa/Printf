/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:52:05 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/20 11:52:40 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_flags
{
	int		width;
	int		precision;
	int     is_prec;
	int 	zero_filler;
	int		neg_number;
	int 	minus;
	int 	zero;
	int		strlen;
	int 	i;
	char 	type;
}				t_flags;

int			g_return;

int			ft_strlen(const char *s);
void		ft_putchar(char c);
int			ft_printf(const char* fmt, ...);
int			ft_isdigit(int c);
int			ft_strchr(const char *s, int c);
void 		check_fmt(const char *s, t_flags *flags, va_list *ap);
int	 		ft_strchr(const char *s, int c);
void 		ft_process_c(t_flags *flags, va_list ap);
void 		fill_space(int len, char c);
void		ft_putstr(char *s, int maxlen);
void 		ft_process_s(t_flags *flags, va_list ap);
void 		ft_process_di(t_flags *flags, va_list ap);
void 		ft_process_u(t_flags *flags, va_list ap);
void 		ft_process_x(t_flags *flags, va_list ap);
void		ft_flush_char(char c);
void 		ft_process_perc(t_flags *flags);
void 		ft_process_p(t_flags *flags, va_list ap);
void 		ft_process_xx(t_flags *flags, va_list ap);
int			ft_atoi(const char *str);

#endif
