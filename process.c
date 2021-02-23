/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:41:42 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 12:04:59 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"



static int
	protect_atoi(long int result, int is_negative)
{
	if (result * is_negative < -2147483648)
		return (0);
	if (result * is_negative > 2147483647)
		return (-1);
	return (result * is_negative);
}

int
	ft_atoi(const char *nptr)
{
	int			i;
	int			is_negative;
	long int	result;

	result = 0;
	is_negative = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\t' || nptr[i] == '\r'
			|| nptr[i] == '\f' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' &&
			result > -2147483649 && result < 2147483648)
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (protect_atoi(result, is_negative));
}


int		get_size(t_ft_printf *s)
{
	int value;

	value = 0;
	if (s->save_s != NULL)
		return (ft_strlen(s->save_s));
	else if (s->save_s == NULL && s->format == 's')
		return (6);
	if (s->format == 'X' || s->format == 'x')
		return (ft_strlen_x(s));
	if (s->format == 'u')
		return (ft_strlen_int_u(s->save_u));
	if (s->format == 'd' || s->format == 'i')
		return (ft_strlen_int(s->save_d));
	if (s->format == 'c')
		return (1);
	if (s->format == 'p')
		return (ft_strlen_p(s) + 2);
	return (0);
}


void	ft_putnbr_base_l(unsigned long cast, char *base, unsigned int blen)
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
