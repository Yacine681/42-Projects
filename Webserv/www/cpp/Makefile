#FLAG

NAME		=		test.out
CC			=		c++
FLAGS		=		-Wall -Wextra -Werror -std=c++98
RM			=		rm -f
#CHECK		=		-fsanitize=address

#PATH

SRCS		= 	test.cpp
OBJS		=$(SRCS:.cpp=.o)


#COLORS


##

.o .cpp:
								@$(CC) $(FLAGS) -c $< -o $(<:cpp=o) $@

$(NAME):	$(OBJS)
									
									$(CC) $(OBJS) $(FLAGS) -o $(NAME)
								

.SILENT	: $(OBJS) $(NAME)

all	:		$(NAME)

clean	:
				@$(RM) $(OBJS)

fclean	:	clean
					@$(RM) $(NAME)
					
re	:	 fclean all

.PHONY	:	all clean fclean re