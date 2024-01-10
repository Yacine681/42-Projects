# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 08:15:19 by yabed             #+#    #+#              #
#    Updated: 2022/04/06 19:19:25 by yabed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= printf.a

SRCS	= ft_nbr.c \
			ft_print_charactere.c \
			ft_print_hexa_maj.c \
			ft_print_hexa_min.c \
			ft_print_pourcent.c \
			ft_print_ptr.c \
			ft_print_str.c \
			ft_printf.c \
			ft_putchar.c \
			ft_unsigned.c \

OBJS	= $(SRCS:%.c=%.o)

FLAGS	= -Wall -Werror -Wextra

.SILENT: $(OBJS_SRC)

$(NAME):
		gcc $(FLAGS) -c $(SRCS) -I./
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
