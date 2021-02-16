/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:33:02 by nigoncal          #+#    #+#             */
/*   Updated: 2021/01/19 16:09:55 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>


int     parse(const char *str, va_list *a, t_ft_printf *s)
{
      s->format = str[s->pos];
    if(str[s->pos] == '%')
    {
        s->save_c = '%';
    }
   else if(str[s->pos] == 'c' && s->save_c == 0)
        s->save_c = va_arg(*a, int);
   else if(str[s->pos] == 'd' || str[s->pos] == 'i' || str[s->pos] == 'x' || str[s->pos] == 'X')
        s->save_d = va_arg(*a, int);
   else if(str[s->pos] == 's') 
        s->save_s = va_arg(*a, char *);
   else if(str[s->pos] == 'u')
        s->save_u = va_arg(*a, unsigned int);
   else if(str[s->pos] == 'p') // exa minuscule
        s->save_p = va_arg(*a, void *);
    else return(0);

    return(convert(s));
}
