#include "ft_printf.h"
int     parse_flag(const char *str, t_ft_printf *s, va_list *a)
{
   
     while(!(detect_conv(str[s->pos])) && str[s->pos] != '\0')
    {
        if(str[s->pos + 1] == '*' || str[s->pos] == '*')
            s->flag_asterix = 1;
        if((str[s->pos] >= '1' && str[s->pos] <= '9') || str[s->pos] == '*')
        {
            s->flag_nb = 1;
            if(str[s->pos] == '*')
                s->nb_space = va_arg(*a, int);
            else
                s->nb_space = ft_atoi(&str[s->pos]);
        }
       if(str[s->pos] == '-')
        {   
            s->pos++;
            s->flag_negative = 1;
            if(str[s->pos] == '0')
                s->pos++;
            if(str[s->pos] == '*')
            {
                    s->nb_space = va_arg(*a, int);
    if(s->nb_space < 0)
        s->nb_space *= -1;
       
            }
            else
                s->nb_space = ft_atoi(&str[s->pos]);


        }
         if(str[s->pos] == '0')
        {
                s->flag_zero = 1;
                if(str[s->pos + 1] == '*')
                    s->nb_zero = va_arg(*a, int);
                else
                    s->nb_zero = ft_atoi(&str[s->pos]);
                s->detect_char = 1;
            s->pos++;
        }
         if(s->flag_zero == 1 && s->flag_negative == 1)
         {
            s->flag_zero = 0;
            s->nb_zero = 0;
            s->detect_char = 0;
         }
  
       if(str[s->pos] == '*')
            s->pos++;
   while ((str[s->pos] >= '0' && str[s->pos] <= '9'))
            s->pos++;
        if(str[s->pos] == '.')
            parse_precision(str, s, a);
            if(!(check_error(s, str)) && str[s->pos] != '\0')
            return(0);
    }
   // debug_struct(s,1);

if(s->flag_asterix != 0)
    parse_asterix(s); 

return(0);
}

void    parse_precision(const char *str, t_ft_printf *s, va_list *a)
{

    s->flag_precision = 1;
    s->pos++;
if(s->flag_zero != 0 && s->nb_zero != 0)
{
        s->flag_zero = 0;
        s->flag_nb = 1;
        s->nb_space = s->nb_zero;
        s->nb_zero = 0;
}
    if((str[s->pos] >= '0' && str[s->pos] <= '9') || str[s->pos] == '*')
    {

        if(s->nb_zero == 0)
        {
             if(str[s->pos] == '*')
                s->nb_zero = va_arg(*a, int);
            else
                s->nb_zero = ft_atoi(&str[s->pos]);
         
        }
    }
    if(str[s->pos] == '*')
        s->pos++;
    while (str[s->pos] >= '0' && str[s->pos] <= '9')
        s->pos++;

        
    
    //debug_struct(s, 1);
}


void parse_asterix (t_ft_printf *s)
{
    if(s->flag_nb != 0 && s->nb_space < 0)
    {
        s->nb_space *= -1;
        s->flag_negative = 1;
        s->flag_nb = 0;
    }    
    if(s->flag_negative == 1 && s->nb_space < 0)
        s->nb_space *= -1;
    if(s->flag_zero == 1 && s->nb_zero < 0)
    {
            s->flag_negative = 1;
            s->nb_space = s->nb_zero *= -1;
            s->nb_zero = 0;
            s->flag_zero = 0;
    }
    if(s->flag_precision == 1 && s->nb_space == 0 && s->nb_zero != 0)
    {
        s->flag_zero = 1;
        s->flag_nb = 0;
    }
}

            //10.3
        
void       debug_struct(t_ft_printf *s, int etat)
{
if(etat == 1)
{
    printf("\n-- TESTS STRUCT PARSE --\n\n");
    printf("s->flag_zero : %d\n", s->flag_zero);
    printf("s->flag_negative : %d\n", s->flag_negative);
    printf("s->flag_precision : %d \n", s->flag_precision);
    printf("s->flag_nb : %d \n", s->flag_nb);
    printf("s->flag_asterix : %d \n\n", s->flag_asterix);
    printf("s->nb_space : %d\n", s->nb_space);
    printf("s->nb_zero : %d \n\n", s->nb_zero);
}
    
}
