Op	= Op/push.c \
		Op/reverse.c \
		Op/rotate.c \
		Op/swap.c \

Src	= Src/error.c \
		Src/ft_tri_stack.c \
		Src/main.c \
		Src/push_swap_utils.c \
		Src/push_swap_utils1.c \
		Src/push_swap_utils2.c \
		Src/push_swap_utils3.c \
		Src/sort.c \
		Src/sort1.c \
		Src/sort2.c \

NAME = push_swap

CC	= gcc

OBJS_OP	 = $(Op:.c=.o)
OBJS_SRC = $(Src:.c=.o)

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'
FONT_COLOR_RED = '\033[0;31m'

OBJS = $(OBJS_OP) $(OBJS_SRC)	

FLAGS	= -Wall -Werror -Wextra

-include $(OBJS:.o=.d)

.SILENT: $(OBJS_OP) $(OBJS_SRC)

all: $(NAME)

$(NAME): $(OBJS_OP) $(OBJS_SRC)
	@$(CC) $(FLAGS) $^ -o $@
	@echo $(FONT_COLOR_GREEN)"[Executable file created]"$(FONT_COLOR_DEFAULT)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@$(CC) -MM $(FLAGS) $< | sed 's,$(notdir $*).o[ :]*,$*.o $@ : ,g' > $*.d
	@echo $(FONT_COLOR_GREEN)"[$@ object file created]"$(FONT_COLOR_DEFAULT)

clean:
	@rm -f $(OBJS_OP) $(OBJS_SRC) $(OBJS:.o=.d)
	@echo $(FONT_COLOR_RED)"[Object files and dependencies deleted]"$(FONT_COLOR_DEFAULT)

fclean: clean
	@rm -f $(NAME)
	@echo $(FONT_COLOR_RED)"[Executable file deleted]"$(FONT_COLOR_DEFAULT)

re: fclean all

.PHONY: all clean fclean re
