# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 08:58:56 by yabed             #+#    #+#              #
#    Updated: 2022/08/17 21:54:24 by yabed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= Src/ft_atoi.c \
			Src/ft_bzero.c \
			Src/ft_calloc.c \
			Src/ft_isalnum.c \
			Src/ft_isalpha.c \
			Src/ft_isascii.c \
			Src/ft_isdigit.c \
			Src/ft_isprint.c \
			Src/ft_itoa.c \
			Src/ft_memchr.c \
			Src/ft_memcmp.c \
			Src/ft_memcpy.c \
			Src/ft_memmove.c \
			Src/ft_memset.c \
			Src/ft_putchar_fd.c \
			Src/ft_putendl_fd.c \
			Src/ft_putnbr_fd.c \
			Src/ft_putstr_fd.c \
			Src/ft_split.c \
			Src/ft_strchr.c \
			Src/ft_strdup.c \
			Src/ft_striteri.c \
			Src/ft_strjoin.c \
			Src/ft_strlcat.c \
			Src/ft_strlcpy.c \
			Src/ft_strlen.c \
			Src/ft_strmapi.c \
			Src/ft_strncmp.c \
			Src/ft_strnstr.c \
			Src/ft_strrchr.c \
			Src/ft_strtrim.c \
			Src/ft_substr.c \
			Src/ft_tolower.c \
			Src/ft_toupper.c \

OBJS	= $(SRCS:%.c=%.o)

FLAGS	= -Wall -Werror -Wextra

$(NAME):
		gcc $(FLAGS) -c $(SRCS) -I./
		mv *.o Src/
		ar rc $(NAME) $(OBJS)
		mv libft.a Src 

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
		rm -rf Src/libft.a

re: fclean all

.PHONY: all clean fclean re
