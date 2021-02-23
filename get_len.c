/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:39:54 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 15:03:44 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (6);
	while (s[i])
		i++;
	return (i);
}

int		ft_strlen_int(int nb)
{
	int i;

	i = 1;
	if (nb == 0)
		return (1);
	if (nb == 2147483647)
		return (10);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		ft_strlen_int_u(unsigned int nb)
{
	int i;

	i = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		ft_strlen_x(t_ft_printf *s)
{
	int				value;
	unsigned int	temp;

	value = 0;
	temp = (unsigned)s->save_d;
	if (temp < 0)
		temp *= -1;
	if (temp < 16)
		return (1);
	while (temp > 0)
	{
		temp = temp / 16;
		value++;
	}
	return (value);
}

int		ft_strlen_p(t_ft_printf *s)
{
	int				value;
	unsigned long	temp;

	value = 0;
	temp = (unsigned long)s->save_p;
	if (temp < 0)
		temp *= -1;
	if (temp < 16)
		return (1);
	while (temp > 0)
	{
		temp = temp / 16;
		value++;
	}
	return (value);
}
