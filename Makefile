##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

DEFAULT     =   "\033[00m"
RED         =   "\033[31m"
GREEN       =   "\033[1;32m"
TEAL        =   "\033[1;36m"
YELLOW      =   "\033[1;7;25;33m"
MAGENTA     =   "\033[1;3;4;35m"
ERROR       =   "\033[5;7;1;31m"
BLINK       =   "\033[5m"
END         =   "\n"

CC = gcc

SRC             =       $(shell find */*.c)

CFLAGS          =   -g3

OBJ         =   $(SRC:.c=.o)

NAME        =   bsq

%.o:    %.c
	@$(CC)  $(CFLAGS) -c $< -o $@ && \
	printf "["$(GREEN)"OK"$(DEFAULT)"] "$(TEAL)$<$(DEFAULT)" -----> "$(GREEN)$@$(DEFAULT)$(END) || \
	printf "["$(RED)"KO"$(DEFAULT)"] "$(BLINK)$(YELLOW)$^$(DEFAULT)$(END) 1>&2

all:	$(NAME)
	@printf "["$(GREEN)"INFO"$(DEFAULT)"] Compiler: $(CC)"$(END)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@printf "["$(GREEN)"OK"$(DEFAULT)"]"$(TEAL)" Done : "$(GREEN)$@$(DEFAULT)$(END) || \
	printf "["$(RED)"KO"$(DEFAULT)"]"$(BLINK)$(YELLOW)$(NAME)$(DEFAULT)$(END) 1>&2

clean:
	@rm -f $(OBJ)
	@printf "["$(RED)"DEL"$(DEFAULT)"] $(OBJ)"$(END)

fclean:	clean
	@rm -f $(NAME)
	@printf "["$(RED)"DEL"$(DEFAULT)"] $(NAME)"$(END)

re:	fclean all

temp:
	find */* -name "[#,~,.o]" -type f -delete
