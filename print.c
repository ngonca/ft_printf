/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:08:04 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 15:28:50 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(t_ft_printf *s)
{
	while (s->nb_space > 0)
	{
		ft_putchar_fd(' ', 1);
		s->nb_space--;
	}
}

void	print_zero(t_ft_printf *s)
{
	if (s->format == 'p' && s->nb_zero != 0 && s->prefix == 0)
	{
		s->prefix = 1;
		ft_putstr("0x");
		s->nb_zero += 2;
		if (s->flag_precision == 1 && s->save_p == 0)
			ft_putstr("0");
		if (s->nb_zero > 2)
			s->return_value += 2;
		else
			s->return_value += s->nb_space;
	}
	while (s->nb_zero > 0)
	{
		ft_putchar_fd('0', 1);
		s->nb_zero--;
	}
}

void	print_flag(t_ft_printf *s)
{
	if (s->flag_negative == 1 && s->flag_precision == 1)
	{
		print_zero(s);
		print_space(s);
	}
	else
	{
		print_space(s);
		print_zero(s);
	}
}

void	print_nb(t_ft_printf *s)
{
	if (s->format == 's')
		ft_putstr(s->save_s);
	else if (s->format == 'X')
		ft_putnbr_base((unsigned)s->save_d, "0123456789ABCDEF", 16);
	else if (s->format == 'x')
		ft_putnbr_base((unsigned)s->save_d, "0123456789abcdef", 16);
	else if (s->format == 'u')
		ft_putnbr_base((unsigned)s->save_u, "0123456789", 10);
	else
		print_nb2(s);
}

void	print_nb2(t_ft_printf *s)
{
	if (s->format == 'd' || s->format == 'i')
	{
		if (s->save_d < 0)
		{
			if (s->save_d != INT_MIN || s->flag_zero == 0)
				ft_putchar_fd('-', 1);
		}
		if (s->save_d != INT_MIN)
			ft_putnbr_base(s->save_d, "0123456789", 10);
		else
			ft_putstr("2147483648");
	}
	if (s->format == 'c' || s->format == '%')
		ft_putchar_fd(s->save_c, 1);
	if (s->format == 'p')
	{
		if (s->prefix == 0)
			ft_putstr("0x");
		if (s->save_p != 0 || s->flag_precision == 0)
			ft_putnbr_base_l((unsigned long)s->save_p, "0123456789abcdef", 16);
	}
}
