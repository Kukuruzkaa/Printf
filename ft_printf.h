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
	int		minus;
	int		zero;
	int     star;
}				t_flags;

int	ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_printf(const char* fmt, ...);
int	ft_isdigit(int c);



#endif
