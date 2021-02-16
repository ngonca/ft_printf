# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 15:49:47 by nigoncal          #+#    #+#              #
#    Updated: 2021/01/13 12:28:14 by nigoncal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = ft_printf.h 

SRC = write_printf.c\
processing_printf.c\
ft_printf.c\
parse.c\
detect_conv.c\
print_flag.c\
parse_flag.c\
convert_di.c\
init_struct.c\

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
