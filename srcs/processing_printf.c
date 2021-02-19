/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:53:17 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/17 16:03:11 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if(s == NULL)
		return(6);
	while (s[i])
		i++;
	return (i);
}

int     ft_strlen_int(int nb)
{
    int i;

    i = 1;
    if(nb == 0)
    return(1);
	if(nb == 2147483647)
		return(10);
	if(nb == -2147483648)
		return(11);
	if(nb < 0)
	{
		i++;
		nb = nb * -1;
	}
    while(nb > 9)
	{
		nb = nb / 10;
		i++;
	}
		return(i);
}

int     ft_strlen_int_u(unsigned int nb)
{
    int i;

    i = 1;
    if(nb == 0)
    return(1);
	if(nb < 0)
	{
		i++;
		nb = nb * -1;
	}
    while(nb > 9)
	{
		nb = nb / 10;
		i++;
	}
		return(i);
}



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

int ft_strlen_x(t_ft_printf *s)
{
		int value;
			value = 0;
		unsigned int temp;
			temp = (unsigned)s->save_d;
		if(temp < 0)
			temp *= -1;
		if(temp < 16)
			return(1);
		while(temp > 0)
		{
			temp = temp / 16;
			value++;
		}
		return(value);
}
int ft_strlen_p(t_ft_printf *s)
{
		int value;
			value = 0;
		unsigned long temp;
			temp = (unsigned long)s->save_p;
		if(temp < 0)
			temp *= -1;
		if(temp < 16)
			return(1);
		while(temp > 0)
		{
			temp = temp / 16;
			value++;
		}
		return(value);
}


int		get_size(t_ft_printf *s)
{
	int value;
		value = 0;
	if(s->save_s != NULL)
		return(ft_strlen(s->save_s));
	else if (s->save_s == NULL && s->format == 's')
		return(6);
	if(s->format == 'X' || s->format == 'x')
		return(ft_strlen_x(s));
	if(s->format == 'u')
    	return(ft_strlen_int_u(s->save_u));
	if(s->format == 'd' || s->format == 'i')
		return(ft_strlen_int(s->save_d));
	if(s->format == 'c')
		return(1);
	if(s->format == 'p')
		return(ft_strlen_p(s) + 2);
	return(0);
}

void	print_nb(t_ft_printf *s)
{
	if(s->format == 's')
		ft_putstr(s->save_s);
	if(s->format == 'X')
		ft_putnbr_base((unsigned)s->save_d, "0123456789ABCDEF", 16);
	if(s->format == 'x')
		ft_putnbr_base((unsigned)s->save_d , "0123456789abcdef", 16);
	if(s->format == 'u')
    	ft_putnbr_base((unsigned)s->save_u, "0123456789", 10);
	if(s->format == 'd' || s->format == 'i')
	{
	if(s->save_d < 0)
	{

		if(s->save_d != INT_MIN || s->flag_zero == 0)
			ft_putchar_fd('-', 1);
	}
	if(s->save_d != INT_MIN)
		ft_putnbr_base(s->save_d, "0123456789", 10);
	else
		ft_putstr("2147483648");
	}
	if(s->format == 'c' || s->format == '%')
		ft_putchar_fd(s->save_c, 1);
	if(s->format == 'p')
	{
			if(s->prefix == 0)
			ft_putstr("0x");
			if( s->save_p != 0 || s->flag_precision == 0)
			ft_putnbr_base_l((unsigned long)s->save_p, "0123456789abcdef", 16);

	}
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