/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:29:47 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 15:40:52 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flag(const char *str, t_ft_printf *s, va_list *a)
{
	while (!(detect_conv(str[s->pos])) && str[s->pos] != '\0')
	{
		if (str[s->pos + 1] == '*' || str[s->pos] == '*')
			s->flag_asterix = 1;
		if ((str[s->pos] >= '1' && str[s->pos] <= '9') || str[s->pos] == '*')
		{
			s->flag_nb = 1;
			if (str[s->pos] == '*')
				s->nb_space = va_arg(*a, int);
			else
				s->nb_space = ft_atoi(&str[s->pos]);
		}
		parse_flag2(str, s, a);
		parse_flag3(str, s, a);
		if (!(check_error(s, str)) && str[s->pos] != '\0')
			return (0);
	}
	if (s->flag_asterix != 0)
		parse_asterix(s);
	return (0);
}

void	parse_flag2(const char *str, t_ft_printf *s, va_list *a)
{
	if (str[s->pos] == '-')
	{
		s->pos++;
		s->flag_negative = 1;
		if (str[s->pos] == '0')
			s->pos++;
		if (str[s->pos] == '*')
		{
			s->nb_space = va_arg(*a, int);
			if (s->nb_space < 0)
				s->nb_space *= -1;
		}
		else
			s->nb_space = ft_atoi(&str[s->pos]);
	}
	if (str[s->pos] == '0')
	{
		s->flag_zero = 1;
		if (str[s->pos + 1] == '*')
			s->nb_zero = va_arg(*a, int);
		else
			s->nb_zero = ft_atoi(&str[s->pos]);
		s->detect_char = 1;
		s->pos++;
	}
}

void	parse_flag3(const char *str, t_ft_printf *s, va_list *a)
{
	if (s->flag_zero == 1 && s->flag_negative == 1)
	{
		s->flag_zero = 0;
		s->nb_zero = 0;
		s->detect_char = 0;
	}
	if (str[s->pos] == '*')
		s->pos++;
	while ((str[s->pos] >= '0' && str[s->pos] <= '9'))
		s->pos++;
	if (str[s->pos] == '.')
		parse_precision(str, s, a);
}

void	parse_precision(const char *str, t_ft_printf *s, va_list *a)
{
	s->flag_precision = 1;
	s->pos++;
	if (s->flag_zero != 0 && s->nb_zero != 0)
	{
		s->flag_zero = 0;
		s->flag_nb = 1;
		s->nb_space = s->nb_zero;
		s->nb_zero = 0;
	}
	if ((str[s->pos] >= '0' && str[s->pos] <= '9') || str[s->pos] == '*')
	{
		if (s->nb_zero == 0)
		{
			if (str[s->pos] == '*')
				s->nb_zero = va_arg(*a, int);
			else
				s->nb_zero = ft_atoi(&str[s->pos]);
		}
	}
	if (str[s->pos] == '*')
		s->pos++;
	while (str[s->pos] >= '0' && str[s->pos] <= '9')
		s->pos++;
}

void	parse_asterix(t_ft_printf *s)
{
	if (s->flag_nb != 0 && s->nb_space < 0)
	{
		s->nb_space *= -1;
		s->flag_negative = 1;
		s->flag_nb = 0;
	}
	if (s->flag_negative == 1 && s->nb_space < 0)
		s->nb_space *= -1;
	if (s->flag_zero == 1 && s->nb_zero < 0)
	{
		s->flag_negative = 1;
		s->nb_space = s->nb_zero *= -1;
		s->nb_zero = 0;
		s->flag_zero = 0;
	}
	if (s->flag_precision == 1 && s->nb_space == 0 && s->nb_zero != 0)
	{
		s->flag_zero = 1;
		s->flag_nb = 0;
	}
}
