#include "ft_printf.h"
#include "limits.h"

int main ()
{
        int r1, r2;
        
    int as = 0;
    int t = 50;
    int u = 10;

      as = ft_printf("vrai : %0*.*d\n", 5, -5, 8);
   printf("return value : [%d]\n", as);
      as = printf("faux : %0*.*d\n", 5, -5, 8);
    printf("return value : [%d]\n", as);
    


}  

