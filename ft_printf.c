/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:57:11 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/22 09:12:46 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

    
int ft_printf(const char *s, ...)
{

    t_ft_printf l;
    va_list va;
    va_start(va, s);
    init_struct(&l);
    while(s[l.pos])
    {
        reset(&l);
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

    }
       
    return(l.return_value);
}