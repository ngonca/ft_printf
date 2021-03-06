/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:01:22 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 11:05:56 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_ft_printf *s)
{
	s->pos = 0;
	s->return_value = 0;
	s->format = 0;
	s->flag_negative = 0;
	s->flag_asterix = 0;
	s->flag_precision = 0;
	s->flag_zero = 0;
	s->flag_nb = 0;
	s->nb_space = 0;
	s->nb_zero = 0;
	s->prefix = 0;
	s->detect_char = 0;
	s->save_p = NULL;
	s->save_d = 0;
	s->save_c = 0;
	s->save_u = 0;
	s->save_s = NULL;
}

void	init_flag(t_ft_printf *s)
{
	s->detect_char = 0;
	s->flag_negative = 0;
	s->flag_asterix = 0;
	s->flag_precision = 0;
	s->flag_zero = 0;
	s->nb_zero = 0;
	s->nb_space = 0;
}

void	reset(t_ft_printf *s)
{
	s->flag_negative = 0;
	s->flag_asterix = 0;
	s->flag_precision = 0;
	s->flag_zero = 0;
	s->nb_space = 0;
	s->nb_zero = 0;
	s->flag_nb = 0;
	s->detect_char = 0;
	s->save_p = NULL;
	s->save_d = 0;
	s->save_c = 0;
	s->save_u = 0;
	s->save_s = NULL;
}

int		check_spec(const char *str)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (detect_conv(str[i]))
			return (1);
		i++;
	}
	return (0);
}
