Src = Src/get_next_line_utils.c \
		Src/get_next_line.c \
		Src/check_map.c \
	  	Src/check_map1.c \
		Src/create_window.c \
		Src/game.c \
		Src/move.c \
		Src/ft_itoa.c \
		Src/put_map.c \
		Src/put_map1.c \
		Src/read_map.c \
		Src/so_long.c \
		Src/win.c \

NAME = so_long

CC = gcc

OBJS_SRC = $(Src:.c=.o)

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'
FONT_COLOR_RED = '\033[0;31m'

OBJS = $(OBJS_SRC)

FLAGS = -Wall -Werror -Wextra

FLAGS_MLX = -Lmlx -lmlx -framework OpenGl -framework AppKit

.SILENT: $(OBJS_SRC)

all: $(NAME)

$(NAME): $(OBJS)
		 @make -C Printf
		 @make -C mlx 
	 	 @$(CC) $(OBJS_SRC) $(FLAGS) Printf/printf.a -o $(NAME) $(FLAGS_MLX)
		 @echo $(FONT_COLOR_GREEN)[.o created] $(FONT_COLOR_DEFAULT)
		 @echo $(FONT_COLOR_GREEN)[executable file created] $(FONT_COLOR_DEFAULT)
clean:
	@rm -rf $(OBJS_SRC)
	@make fclean -C Printf
	@make clean -C mlx
	@echo $(FONT_COLOR_RED)[.o deleted] $(FONT_COLOR_DEFAULT)

fclean: clean
	@rm -rf $(NAME)
	@echo $(FONT_COLOR_RED)[executable file deleted] $(FONT_COLOR_DEFAULT)

re: fclean all

.PHONY: all clean fclean re
