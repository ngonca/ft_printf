    #include "ft_printf.h"

int     convert( t_ft_printf *s)
{
  if(!(format_exception(s)))
        return(0);

        if(s->flag_precision == 1 && s->format != 's')
        {
            if(s->nb_zero != 0 && s->flag_nb == 0)
                s->flag_zero = 1;
            else
                s->flag_nb = 1;
            if(s->save_d < 0 && s->nb_zero != 0 && s->format != 'x' && s->format != 'X')
                 s->nb_zero++;
        }
        if(s->format == 's' && s->nb_zero != 0)
        {
                return(precision_string(s));
        }

       if(s->format == 'c')
            parse_c(s);
        if(s->flag_precision == 1 && s->nb_space != 0 && s->nb_zero != 0)
        {
            precision(s);
            return(print(s));
        }

        if(s->flag_nb != 0 || s->flag_negative != 0)
            parse_di(s, &s->nb_space);
        if(s->flag_zero != 0 )
            parse_di(s, &s->nb_zero);
        return(print(s));
}

void    parse_di(t_ft_printf *s, int *nb)
{

    if(s->flag_zero != 0 && s->save_d < 0 && s->format != 'x' && s->format != 'X')
        revers_nb(s);
    if(get_size(s) < *nb)
            s->return_value += *nb;
    else
        s->return_value += get_size(s);
     *nb = *nb - get_size(s);
}

void    precision(t_ft_printf *s) 
{

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
        if (s->nb_zero != 0 && s->save_d < 0 && s->format != 'x' && s->format != 'X' && s->nb_zero > 0)
        {
            s->nb_zero++;
            s->return_value--;
            if(s->flag_negative == 1 && s->flag_precision == 1)
                revers_nb(s);
            else
            {
                revers_nb(s);
                print_space(s);
            }
        }
}

int        print(t_ft_printf *s)
{
    if(s->flag_precision == 1 && s->flag_negative == 1)
    {
        print_zero(s);
        print_nb(s);
        return(0);
    }
    if(s->flag_zero != 0 || s->flag_nb != 0)
    {
        print_flag(s);
        print_nb(s);
    }
    if(s->flag_negative != 0 && s->flag_precision == 0 )
    {
        print_nb(s);
        print_flag(s);
    }
    if(!(detect_flag(s)))
     {
            print_nb(s);
         return(get_size(s));
    }
        return(0);
}
void    revers_nb(t_ft_printf *s)
{
       
                s->save_d *= -1;
                if(s->nb_zero != 0)
                    s->nb_zero--;
                    if(s->flag_negative == 0) 
               print_space(s);
                write(1, "-", 1);
                s->return_value++;
}


int       format_exception(t_ft_printf *s)
{

/*if(s->nb_zero < 0 && s->nb_space > 0)
    s->flag_zero =1;*/
debug_struct(s, 0);
if(s->nb_zero > ft_strlen_int(s->save_d) && s->save_d == INT_MIN && (s->format == 'd' || s->format == 'i'))
{
    s->nb_zero++;
    s->return_value--;
}
if(s->flag_precision != 0 && s->save_p == 0 && s->nb_space > 2 && s->format == 'p')
{
    s->return_value--;
    s->nb_space++;
}

if(s->nb_space == 0 && s->nb_zero == 0 && s->flag_zero == 1)
    s->flag_zero = 0;
if(s->format == 's' && s->nb_zero < 0 && s->nb_space != 0)
{
   if(s->nb_space < get_size(s))
    s->return_value += get_size(s) - s->nb_space;
}
if(s->flag_precision == 1 && s->save_p == NULL && s->format == 'p' && s->nb_space == 0 && s->nb_zero == 0)
      s->return_value--;

    if(s->format == '%')
    {
        s->format = 'c';
        return(1);
    }
    if(s->nb_zero < 0 && s->format == 's')
    {
        s->nb_zero = ft_strlen(s->save_s);
    }

    if(s->flag_precision == 1 && s->nb_space == 0 && s->nb_zero == 0 && s->save_d == 0 
        && s->format != 'u' && s->format != 'c' && s->format != 'p')
        return(0);
    if(s->format == 'u' && s->save_u == 0 && s->flag_precision == 1 && s->nb_zero == 0)
    {
            s->return_value += s->nb_space;
            return(0);
    }
    if(s->flag_precision == 1 && s->save_d == 0 && s->nb_zero == 0 && s->format != 'u' && s->format != 'p')
        {
            s->return_value += s->nb_space;
            return(0);
        }
    return(1);
}

int     precision_string(t_ft_printf *s)
{
    
    s->return_value += s->nb_space;
    if(s->nb_space < get_size(s) && s->nb_zero > get_size(s))
        s->return_value += get_size(s) - s->nb_space;
    if(s->nb_space == 0 && s->nb_zero <= get_size(s))
        s->return_value += s->nb_zero;
    if(s->nb_zero > get_size(s))
        s->nb_space -= get_size(s);
    else
        s->nb_space -= s->nb_zero;
    if(s->flag_negative == 1 && s->flag_precision == 1)
    {
        if(s->format == 's' && s->save_s != NULL)
            ft_putstr_precision(s->save_s, s->nb_zero);
        else
            ft_putstr_precision("(null)", s->nb_zero);
            print_space(s);
            s->nb_zero = 0;
            return(0);
    }
    print_space(s);
        if(s->format == 's' && s->save_s != NULL)
            ft_putstr_precision(s->save_s, s->nb_zero);
        else
            ft_putstr_precision("(null)", s->nb_zero);
    s->nb_zero = 0;
    return(0);
}

void    parse_c(t_ft_printf *s)
{
    
    if(s->nb_space == 0 && s->nb_zero != 0 && s->flag_zero == 1 && s->flag_precision == 1)
    {
        s->nb_zero = 0;
    }
    if(s->nb_space != 0 && s->nb_zero != 0 && s->detect_char == 0)
    {
        if(s->flag_negative == 1)
            s->return_value--;
        s->nb_zero = 0;
    }
    if(s->detect_char == 1 && s->nb_space != 0)
    {
    
            s->nb_zero = s->nb_space;
            s->nb_space = 0;
            s->flag_zero = 1;
            s->return_value--;
    }
}