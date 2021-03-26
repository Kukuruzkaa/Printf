/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:45:35 by ddiakova          #+#    #+#             */
/*   Updated: 2021/03/20 11:51:21 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int		l;

	l = 0;
	while (s[l] != '\0')
	{
		l++;
	}
	return (l);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s, int maxlen)
{
	int i;

	i = 0;
	while (s[i] != '\0' && i < maxlen)
	{
		ft_putchar(s[i]);
		i++;
	}
}

void 	fill_space(int len, char c)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	 ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (*s == c)
		return (1);
	return (0);
}
