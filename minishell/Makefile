FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'
FONT_COLOR_RED = '\033[0;31m'

NAME = minishell
CC = gcc
FLAGS = -Wall -Werror -Wextra 
RM = rm -f
LIBFT_NAME = libft/libft.a
LIBFT = make -C ./libft
LIBFT_CLEAN = make clean -C ./libft
LIBFT_FCLEAN = make fclean -C ./libft
LINK = -lreadline -L$(HOME)/.brew/opt/readline/lib 
COMPILE = -I/$(HOME)/.brew/opt/readline/include -g
OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

SRC = src/cd.c \
			src/cmd.c \
			src/create_pipe.c \
			src/dollar_point.c \
			src/echo.c \
			src/env.c \
			src/exec.c \
			src/export.c \
			src/export_utils.c \
			src/utils.c \
			src/ft_exit.c \
			src/minishell.c \
			src/parsing.c \
			src/parsing2.c \
			src/pwd.c \
			src/ft_free.c \
			src/signal.c \
			src/unset.c \
			src/redirection/redirection.c \
			src/redirection/redirection1.c \
			src/redirection/redirection2.c \
			src/redirection/redirection3.c \
			src/redirection/redirection4.c \

all: $(NAME)

$(NAME): $(OBJ)
			$(LIBFT) && $(CC) $(FLAGS) $(LINK) $(OBJ) $(LIBFT_NAME) -o $(NAME)
			@echo $(FONT_COLOR_GREEN)[Compilation success] $(FONT_COLOR_DEFAULT)
%.o: %.c
			$(CC) $(FLAGS) $(COMPILE) -c $< -o $@

clean: 
			@$(RM) $(OBJ) && $(LIBFT_CLEAN)
			@echo $(FONT_COLOR_RED)[OBJECT DELETED] $(FONT_COLOR_DEFAULT)

fclean: clean
			@$(RM) $(NAME) && $(LIBFT_FCLEAN)
			@echo $(FONT_COLOR_RED)[MINISHELL DELETED] $(FONT_COLOR_DEFAULT)

re: fclean all

.PHONY: all clean fclean re
