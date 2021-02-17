#include"ft_printf.h"

void print_space(t_ft_printf *s)
{

        while(s->nb_space > 0)
        {
            ft_putchar_fd(' ', 1);
            s->nb_space--;
        }
 
}
void print_zero(t_ft_printf *s)
{
        if(s->format == 'p' && s->nb_zero != 0 && s->prefix == 0)
        {       s->prefix = 1;
                ft_putstr("0x");
                s->nb_zero += 2;
                if(s->flag_precision == 1 && s->save_p == 0)    
                        ft_putstr("0");
                if(s->nb_zero > 2)
                        s->return_value += 2;
                else
                        s->return_value += s->nb_space;
        }

          while(s->nb_zero > 0)
        {
            ft_putchar_fd('0', 1);
            s->nb_zero--;
        }
}

void print_flag(t_ft_printf *s)
{
        if(s->flag_negative == 1 && s->flag_precision == 1)
        {
                print_zero(s);
                print_space(s);
        }
        else
        {
                print_space(s);
                print_zero(s);
        }
}
