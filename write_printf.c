/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:52:54 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 12:12:54 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_putstr_precision(char *s, int precision)
{
	int i;

	i = 0;
	if (precision < 0)
		return (0);
	while (precision != i && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
	else
		ft_putstr("(null)");
}

void	ft_putnbr_fd_u(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr_fd_u((n / 10), fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

void	ft_putnbr_base(long cast, char *base, int blen)
{
	if (cast < 0)
		cast = -cast;
	if (cast < blen)
		write(1, &base[cast], 1);
	else
	{
		ft_putnbr_base(cast / blen, base, blen);
		write(1, &base[cast % blen], 1);
	}
}
