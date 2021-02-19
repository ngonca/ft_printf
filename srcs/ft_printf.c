/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:57:11 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/17 15:34:50 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
	int			pos;
	int 		retv;
    t_ft_printf l;
    va_list		va;

    va_start(va, s);
    pos = 0;
    retv = 0;
    l = (t_ft_printf) {.pos = 0};
    while(s[l.pos])
    {
    	l = (t_ft_printf) {.pos = pos, .return_value = retv};
        if(s[l.pos] == '%' && (check_spec(s)))
        {
            l.pos++;
            parse_flag(s, &l, &va);
            l.return_value += parse(s, &va, &l);
            print_flag(&l);
            l.pos++;
        }
        else
        {
            ft_putchar_fd(s[l.pos], 1);
            l.return_value++;
            l.pos++;
        }
		pos = l.pos;
        retv = l.return_value;
    }
       
    return(l.return_value);
}