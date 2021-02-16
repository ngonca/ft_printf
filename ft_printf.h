# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <stdarg.h>
#include <limits.h>

void    check_format(const char s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_fd_u(unsigned int n, int fd);
int     ft_printf(const char *s, ...);
int     ft_strlen_int_u(unsigned int nb);
void     print_flag_left(char flag, int nb);
void     print_flag_right(char flag, int nb);

int     ft_strlen_int (int nb);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);      
int		ft_isalnum(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_isprint(int c);
int		ft_isnum(int c);
void	ft_putchar_fd(char c, int fd);
void    ft_putstr(char *s);
int 	ft_putstr_len(char *s, int len);
void	ft_putendl_fd(char *s, int fd);
char    *itoa_base( unsigned int value, int base);
char    *itoa_base_maj(unsigned int value, int base);
char    *itoa_base_p(long unsigned int value, int base);
void	ft_putnbr_base(long cast, char *base, int blen);
int     ft_putstr_precision(char *s, int precision);
int		detect_conv(char c);

typedef	struct	s_ft_printf
{
    int         error;
    int         format;
    int         flag_negative;	
    int         flag_asterix;
    int         flag_precision;
    int         flag_zero;
    int         nb_zero;
    int         nb_space;
	int			return_value;
    int			pos;
    int         flag_nb;
    int         detect_char;

    int             save_d;
    char            save_c;
    unsigned int    save_u;
    char            *save_s;
    void            *save_p;
}               t_ft_printf;
int     check_error(t_ft_printf *s, const char *str);
void    reset(t_ft_printf *s);
void    parse_c(t_ft_printf *s);
void    detect_asterix(const char *str, t_ft_printf *s);
void     debug_struct(t_ft_printf *s, int etat);
void    parse_asterix (t_ft_printf *s);
void	ft_putnbr_base_l(unsigned long cast, char *base, unsigned int blen);
int     ft_strlen_p(t_ft_printf *s);
void    parse_precision(const char *str, t_ft_printf *s, va_list *a);
void	print_nb(t_ft_printf *s);
int		get_size(t_ft_printf *s);
int     egine_printf(const char *str, va_list *a, t_ft_printf *s);
int		detect_flag(t_ft_printf *s);
void    precision(t_ft_printf *s);
int     precision_string(t_ft_printf *s);
int     check_safety(t_ft_printf *s);
void    init_struct(t_ft_printf *s);
void    init_flag(t_ft_printf *s);
int     convert( t_ft_printf *s);
int     convert_s(va_list *a, t_ft_printf *s);
int     convert_percent(t_ft_printf *s);
void    parse_s(t_ft_printf *s, int *nb);
void    init_struct(t_ft_printf *s);

void    precision(t_ft_printf *s);
int      precision_u(t_ft_printf *s);
void     precision_s(t_ft_printf *s);
void    precision_Xx(t_ft_printf *s);
int    parse(const char *str, va_list *a, t_ft_printf *s);
void    parse_di(t_ft_printf *s, int *nb);
int     parse_flag(const char *str, t_ft_printf *s, va_list *a);
void    print_space(t_ft_printf *s);
void    print_zero(t_ft_printf *s);
void    print_flag(t_ft_printf *s);
int        print(t_ft_printf *s);
void    revers_nb(t_ft_printf *s);
int       format_exception(t_ft_printf *s);