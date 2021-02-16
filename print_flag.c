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
