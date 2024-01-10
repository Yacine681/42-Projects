Src = check_argument.c \
		check_death.c \
		conditions.c \
		destroy_mutexes.c \
		init_param.c \
		philo_utils.c \
		philo.c \
		routines.c \
		simulation.c \

NAME = philo

CC = gcc

OBJS_SRC = $(Src:.c=.o)

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'
FONT_COLOR_RED = '\033[0;31m'

OBJS = $(OBJS_SRC)

FLAGS = -Wall -Werror -Wextra

.SILENT: $(OBJS_SRC)

all: $(NAME)

$(NAME): $(OBJS)
	 	 @$(CC) -pthread $(OBJS_SRC) $(FLAGS) -g -o $(NAME)
		 @echo $(FONT_COLOR_GREEN)[.o created] $(FONT_COLOR_DEFAULT)
		 @echo $(FONT_COLOR_GREEN)[executable file created] $(FONT_COLOR_DEFAULT)
clean:
	@rm -rf $(OBJS_SRC)
	@echo $(FONT_COLOR_RED)[.o deleted] $(FONT_COLOR_DEFAULT)

fclean: clean
	@rm -rf $(NAME)
	@echo $(FONT_COLOR_RED)[executable file deleted] $(FONT_COLOR_DEFAULT)

re: fclean all

.PHONY: all clean fclean re
