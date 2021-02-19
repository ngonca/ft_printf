/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:06:20 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/17 10:50:39 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		detect_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		detect_flag(t_ft_printf *s)
{
	if(s->flag_negative != 0 || s->flag_nb != 0 || s->flag_precision != 0 
		|| s->flag_zero != 0 || s->flag_asterix != 0)
		return(1);
	return(0);
}

int		check_error (t_ft_printf *s, const char *str)
{
	if(str[s->pos] == '*' || str[s->pos] == '-' || str[s->pos] == '.')
		return(1);
	else if(detect_conv(str[s->pos]))
		return(1);
	else if (str[s->pos] >= '0' && str[s->pos] <= '9')
		return(1);
	else if(str[s->pos] == '\0')
		return(1);
	else
		return(0);
}
