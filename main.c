#include "ft_printf.h"
#include "limits.h"

int main ()
{
        int r1, r2;
        
    int as = 0;
    int t = 50;
    int u = 10;

          as = ft_printf("faux : %3.6s\n", "hislodw");
   printf("return value : [%d]\n", as);
      as = printf("vrai : %3.6s\n", "hislodw");
    printf("return value : [%d]\n", as);
    


}  
