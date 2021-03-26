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
	int 	minus;
	int 	zero;
	int		strlen;
	int 	i;
	char 	type;
}				t_flags;

int	ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_printf(const char* fmt, ...);
int	ft_isdigit(int c);
int	ft_strchr(const char *s, int c);
void 	check_fmt(const char *s, t_flags *flags);
int	 ft_strchr(const char *s, int c);
void 	ft_process_c(t_flags *flags, va_list ap);
void 	fill_space(int len, char c);
void	ft_putstr(char *s, int maxlen);
void 	ft_process_s(t_flags *flags, va_list ap);
#endif
