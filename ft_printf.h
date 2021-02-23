/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:21:04 by nigoncal          #+#    #+#             */
/*   Updated: 2021/02/23 12:08:28 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

int					ft_printf(const char *s, ...) __attribute__((format(printf,1,2)));
void				ft_putnbr_fd(int n, int fd);
int					ft_strlen_int_u(unsigned int nb);
int					ft_strlen_int (int nb);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *nptr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *s);
void				ft_putnbr_base(long cast, char *base, int blen);
int					ft_putstr_precision(char *s, int precision);
int					detect_conv(char c);
int					check_spec(const char *str);

typedef	struct		s_ft_printf
{
	int				format;
	int				flag_negative;
	int				flag_asterix;
	int				flag_precision;
	int				flag_zero;
	int				nb_zero;
	int				nb_space;
	int				return_value;
	int				pos;
	int				flag_nb;
	int				detect_char;
	int				prefix;
	int				save_d;
	char			save_c;
	unsigned int	save_u;
	char			*save_s;
	void			*save_p;
}					t_ft_printf;
void 				print_nb2 (t_ft_printf *s);
void				format_excep2(t_ft_printf *s);
int					format_error(t_ft_printf *s);
void				format_excep(t_ft_printf *s);
void				reset(t_ft_printf *s);
void				init_struct(t_ft_printf *s);
int					check_error(t_ft_printf *s, const char *str);
void				parse_c(t_ft_printf *s);
void				parse_asterix (t_ft_printf *s);
void				ft_putnbr_base_l(unsigned long cast, char *base, unsigned int blen);
int					ft_strlen_p(t_ft_printf *s);
int					ft_strlen_x(t_ft_printf *s);
void				parse_precision(const char *str, t_ft_printf *s, va_list *a);
void				print_nb(t_ft_printf *s);
int					get_size(t_ft_printf *s);
int					detect_flag(t_ft_printf *s);
void				precision(t_ft_printf *s);
int					precision_s(t_ft_printf *s);
int					convert(t_ft_printf *s);
void				precision(t_ft_printf *s);
int					parse(const char *str, va_list *a, t_ft_printf *s);
void				parse_all(t_ft_printf *s, int *nb);
int					parse_flag(const char *str, t_ft_printf *s, va_list *a);
void				print_space(t_ft_printf *s);
void				print_zero(t_ft_printf *s);
void				print_flag(t_ft_printf *s);
int					print(t_ft_printf *s);
void				revers_nb(t_ft_printf *s);
#endif
