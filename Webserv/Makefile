#FLAG

NAME		=		webserv
CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98
RM			=		rm -f
#CHECK		=		-fsanitize=address

#PATH

SRCS		= 	srcs/Cgi.cpp srcs/ConfigParse.cpp srcs/Mime.cpp srcs/ServerManager.cpp srcs/Client.cpp srcs/ConfigServer.cpp \
						srcs/Request.cpp srcs/main.cpp srcs/ConfigFile.cpp srcs/Location.cpp srcs/Response.cpp srcs/utiles.cpp
OBJS		=		$(SRCS:.cpp=.o)
HEADER	=		inc/Cgi.hpp inc/ConfigParse.hpp inc/Mime.hpp inc/ServerManager.hpp inc/Client.hpp inc/ConfigServer.hpp \
						inc/Request.hpp inc/utiles.hpp inc/ConfigFile.hpp inc/Location.hpp inc/Response.hpp

#COLORS

_GREY		=		$'\x1b[33m
_GREEN	=		$'\x1b[32m

##

.o : .cpp $(HEADER) Makefile
								@$(CC) $(FLAGS) -c $< -o $(<:cpp=o) $@

$(NAME):	$(OBJS)
									@echo "$(_GREY)Compilation Webserv loading...$(_END)"
									make -C www/cpp
									$(CC) $(OBJS) $(FLAGS) -o $(NAME)
									@echo "$(_GREEN)$(_BOLD)Compilation done!$(_END)"

.SILENT	: $(OBJS) $(NAME)

all	:		$(NAME)

clean	:
				@$(RM) $(OBJS)
				make clean -C www/cpp

fclean	:	clean
					@$(RM) $(NAME)
					make fclean -C www/cpp
					@echo "$(_GREEN)$(_BOLD)Exec & .o have been erased!$(_END)"
re	:	 fclean all

.PHONY	:	all clean fclean re

