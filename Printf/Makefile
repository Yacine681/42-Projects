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

NAME	= libftprintf.a

SRCS	= Src/ft_nbr.c \
			Src/ft_print_charactere.c \
			Src/ft_print_hexa_maj.c \
			Src/ft_print_hexa_min.c \
			Src/ft_print_pourcent.c \
			Src/ft_print_ptr.c \
			Src/ft_print_str.c \
			Src/ft_printf.c \
			Src/ft_putchar.c \
			Src/ft_unsigned.c

OBJS	= $(SRCS:.c=.o)

FLAGS	= -Wall -Werror -Wextra

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

%.o: %.c
		gcc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

