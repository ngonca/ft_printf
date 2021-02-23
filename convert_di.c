/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:30:55 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 14:38:27 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert(t_ft_printf *s)
{
	if (!(format_error(s)))
		return (0);
	format_excep(s);
	if (s->flag_precision == 1 && s->format != 's')
	{
		if (s->nb_zero != 0 && s->flag_nb == 0)
			s->flag_zero = 1;
		else
			s->flag_nb = 1;
		if (s->save_d < 0 && s->nb_zero != 0
			&& s->format != 'x' && s->format != 'X')
			s->nb_zero++;
	}
	if (s->format == 's' && s->nb_zero != 0)
		return (precision_s(s));
	if (s->flag_precision == 1 && s->nb_space != 0 && s->nb_zero != 0)
	{
		precision(s);
		return (print(s));
	}
	if (s->flag_nb != 0 || s->flag_negative != 0)
		parse_all(s, &s->nb_space);
	if (s->flag_zero != 0)
		parse_all(s, &s->nb_zero);
	return (print(s));
}

void	precision(t_ft_printf *s)
{
	if (s->format == 'p' && s->nb_space > 2 && s->nb_zero != 0)
		s->nb_space -= 2;
	if (s->nb_zero < get_size(s))
		s->nb_space -= get_size(s);
	else
		s->nb_space -= s->nb_zero;
	s->nb_zero -= get_size(s);
	if (s->nb_zero > 0)
		s->return_value += s->nb_zero + get_size(s);
	else
		s->return_value += get_size(s);
	if (s->nb_space > 0)
		s->return_value += s->nb_space;
	precision2(s);
}

void	precision2(t_ft_printf *s)
{
	if (s->nb_zero != 0 && s->save_d < 0 && s->format != 'x'
		&& s->format != 'X' && s->nb_zero > 0)
	{
		s->nb_zero++;
		s->return_value--;
		if (s->flag_negative == 1 && s->flag_precision == 1)
			revers_nb(s);
		else
		{
			revers_nb(s);
			print_space(s);
		}
	}
}

int		print(t_ft_printf *s)
{
	if (s->flag_precision == 1 && s->flag_negative == 1)
	{
		print_zero(s);
		print_nb(s);
		return (0);
	}
	if (s->flag_zero != 0 || s->flag_nb != 0)
	{
		print_flag(s);
		print_nb(s);
	}
	if (s->flag_negative != 0 && s->flag_precision == 0)
	{
		print_nb(s);
		print_flag(s);
	}
	if (!(detect_flag(s)))
	{
		print_nb(s);
		return (get_size(s));
	}
	return (0);
}

int		precision_s(t_ft_printf *s)
{
	if (s->nb_zero <= get_size(s) && s->nb_space > 0
		&& s->nb_space < s->nb_zero && s->flag_asterix == 0)
		s->return_value += s->nb_zero - s->nb_space;
	s->return_value += s->nb_space;
	if (s->nb_space < get_size(s) && s->nb_zero > get_size(s))
		s->return_value += get_size(s) - s->nb_space;
	if (s->nb_space == 0 && s->nb_zero <= get_size(s))
		s->return_value += s->nb_zero;
	if (s->nb_zero > get_size(s))
		s->nb_space -= get_size(s);
	else
		s->nb_space -= s->nb_zero;
	print_precision(s);
	return (0);
}
