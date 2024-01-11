# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 13:25:16 by yabed             #+#    #+#              #
#    Updated: 2024/01/11 11:39:30 by yabed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME			= libft.a

CC 			= gcc
CFLAGS 			= -Wall -Wextra -Werror


SRCS			= 	get_next_line.c get_next_line_utils.c ft_isalnum.c ft_isalpha.c \
					ft_isascii.c ft_isdigit.c ft_isprint.c ft_lstadd_back.c \
					ft_lstadd_front.c ft_lstclear.c ft_lstlast.c ft_lstnew.c \
					ft_lstsize.c ft_bzero.c ft_calloc.c ft_memalloc.c ft_realloc.c \
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_free_tab.c \
					ft_memset.c ft_add_flags.c ft_conv_char.c ft_conv_hex.c \
					ft_conv_int.c ft_conv_ptr.c ft_conv_str.c ft_conv_uint.c \
					ft_define_args.c ft_get_opts.c ft_printf.c ft_put_size.c \
					ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c ft_putstr.c \
					ft_putnbr_fd.c ft_putnbr.c ft_putendl_fd.c ft_putendl.c \
					ft_putnbr_base.c ft_atoi.c ft_atol.c ft_itoa.c ft_itoa_hex.c \
					ft_itoa_ptr.c ft_itoa_unsigned.c ft_tolower.c ft_toupper.c \
					ft_insert_str.c ft_split.c ft_strcat.c ft_strchr.c \
					ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
					ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
					ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
					ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
					ft_strstr.c ft_strtrim.c ft_substr.c ft_strndup.c ft_split_str.c \

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:			clean
			@rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:			all clean fclean re bonus
