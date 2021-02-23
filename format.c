/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:35:12 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 14:37:52 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_excep(t_ft_printf *s)
{
	if (s->flag_precision == 1 && s->flag_negative == 1 && s->nb_space == 0)
		s->flag_negative = 0;
	if (s->flag_precision == 1 && s->detect_char == 1
		&& s->nb_zero < 0 && s->nb_space > 0)
		s->nb_zero = s->nb_space;
	if (s->format == 's' && s->flag_zero == 1 && s->flag_precision == 0)
	{
		s->flag_zero = 0;
		s->nb_zero = 0;
	}
	if (s->nb_zero > ft_strlen_int(s->save_d) && s->save_d == INT_MIN
		&& (s->format == 'd' || s->format == 'i'))
	{
		s->nb_zero++;
		s->return_value--;
	}
	if (s->flag_precision != 0 && s->save_p == 0
		&& s->nb_space > 2 && s->format == 'p')
	{
		s->return_value--;
		s->nb_space++;
	}
	format_excep2(s);
}

void	format_excep2(t_ft_printf *s)
{
	if (s->format == 'c')
		parse_c(s);
	if (s->nb_space == 0 && s->nb_zero == 0
		&& s->flag_zero == 1 && s->flag_precision == 1)
		s->flag_zero = 0;
	if (s->format == 's' && s->nb_zero < 0 && s->nb_space != 0)
	{
		if (s->nb_space < get_size(s))
			s->return_value += get_size(s) - s->nb_space;
	}
	if (s->flag_precision == 1 && s->save_p == NULL
		&& s->format == 'p' && s->nb_space == 0 && s->nb_zero == 0)
		s->return_value--;
	if (s->format == '%')
		s->format = 'c';
	if (s->nb_zero < 0 && s->format == 's')
		s->nb_zero = ft_strlen(s->save_s);
}

int		format_error(t_ft_printf *s)
{
	if (s->format == 'u' && s->save_u == 0
		&& s->flag_precision == 1 && s->nb_zero == 0)
	{
		s->return_value += s->nb_space;
		return (0);
	}
	else if (s->flag_precision == 1 && s->save_d == 0 && s->nb_zero == 0
		&& s->format != 'u' && s->format != 'p' && s->format != 'c')
	{
		s->return_value += s->nb_space;
		return (0);
	}
	else if (s->flag_precision == 1 && s->nb_space == 0
			&& s->nb_zero == 0 && s->save_d == 0
			&& s->format != 'u' && s->format != 'c' && s->format != 'p')
		return (0);
	else
		return (1);
}

void	parse_c(t_ft_printf *s)
{
	if (s->nb_space == 0 && s->nb_zero != 0
		&& s->flag_zero == 1 && s->flag_precision == 1)
		s->nb_zero = 0;
	if (s->nb_space != 0 && s->nb_zero != 0 && s->detect_char == 0)
	{
		if (s->flag_negative == 1)
			s->return_value--;
		s->nb_zero = 0;
	}
	if (s->detect_char == 1 && s->nb_space != 0)
	{
		s->nb_zero = s->nb_space;
		s->nb_space = 0;
		s->flag_zero = 1;
		s->return_value--;
	}
}

void	print_precision(t_ft_printf *s)
{
	if (s->flag_negative == 1 && s->flag_precision == 1)
	{
		if (s->format == 's' && s->save_s != NULL)
			ft_putstr_precision(s->save_s, s->nb_zero);
		else
			ft_putstr_precision("(null)", s->nb_zero);
		print_space(s);
		s->nb_zero = 0;
	}
	print_space(s);
	if (s->format == 's' && s->save_s != NULL)
		ft_putstr_precision(s->save_s, s->nb_zero);
	else
		ft_putstr_precision("(null)", s->nb_zero);
	s->nb_zero = 0;
}
