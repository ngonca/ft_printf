.PHONY: all clean fclean re

# Name of file
NAME		=	libftprintf.a

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs

# List of sources
SRCS		=	$(addprefix $(PATH_SRC)/, convert_di.c detect_conv.c ft_printf.c init_struct.c parse.c parse_flag.c print_flag.c processing_printf.c write_printf.c)
OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(addprefix $(PATH_INC)/, ft_printf.h)

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Werror -Wextra
COMP_ADD	=	-I$(PATH_INC)

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\e[38;5;184m
_GREEN		=	\e[38;5;46m
_RESET		=	\e[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init:
	@ $(shell mkdir -p $(PATH_OBJ))

$(NAME): $(OBJS) $(INCS)
	ar rcs $(NAME) $(OBJS)

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c $(INCS)
	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

clean:
	@ $(RM) -rf $(PATH_OBJ)

fclean: clean
	@ $(RM) -rf $(NAME)

re: fclean all
