Server	= Src/server.c
Client	= Src/client.c
Utils	= Src/minitalk_utils.c

CC	= gcc

OBJS_SERVER	= $(Server:.c=.o)
OBJS_CLIENT	= $(Client:.c=.o)
OBJS_UTILS	= $(Utils:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'
FONT_COLOR_RED = '\033[0;31m'

OBJS = $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_UTILS)

FLAGS	= -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTILS)
	@$(CC) $(FLAGS) $^ -o $@
	@echo $(FONT_COLOR_GREEN)"[$@ executable created]"$(FONT_COLOR_DEFAULT)

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS)
	@$(CC) $(FLAGS) $^ -o $@
	@echo $(FONT_COLOR_GREEN)"[$@ executable created]"$(FONT_COLOR_DEFAULT)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo $(FONT_COLOR_GREEN)"[$@ object file created]"$(FONT_COLOR_DEFAULT)

clean:
	@rm -f $(OBJS)
	@echo $(FONT_COLOR_RED)"[object files deleted]"$(FONT_COLOR_DEFAULT)

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@echo $(FONT_COLOR_RED)"[executable files deleted]"$(FONT_COLOR_DEFAULT)

re: fclean all