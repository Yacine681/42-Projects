Src = main.cpp \
	  	Base.cpp \

NAME = Base

++ = g++

OBJS_SRC = $(Src:.cpp=.o)

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'
FONT_COLOR_RED = '\033[0;31m'

OBJS = $(OBJS_SRC)

FLAGS = -Wall -Werror -Wextra -std=c++98

.SILENT: $(OBJS_SRC)

all: $(NAME)

$(NAME): $(OBJS)
	 	 @$(++) $(OBJS_SRC) $(FLAGS) -o $(NAME)
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
