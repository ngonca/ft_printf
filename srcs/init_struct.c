#include "ft_printf.h"

int check_spec(const char *str)
{
    int i;
        i = 1;
    while(str[i] != '\0')
    {
        if(detect_conv(str[i]))
            return(1);
        i++;
    }
    return(0);
}   