# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 15:49:47 by nigoncal          #+#    #+#              #
#    Updated: 2021/02/23 12:13:37 by nigoncal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = ft_printf.h 

SRC = write_printf.c\
print.c\
process.c\
ft_printf.c\
parse.c\
detect_conv.c\
print.c\
parse_flag.c\
convert_di.c\
init_struct.c\
get_len.c\

OBJS	= $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :	$(OBJS)
	ar rc $(NAME) $(OBJS)

%.o:%.c $(HEADER)
	gcc $(FLAG) -o $@ -c $< -I $(HEADER)
clean :
	/bin/rm -f $(OBJS)

fclean : clean
	/bin/rm -f $(NAME)

re: fclean all
