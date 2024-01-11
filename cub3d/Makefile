NAME = cub3D
OBJ_DIR		=	obj/
SRCS_DIR	=	src/
SRCS		=	main.c				\
				minimap.c			\
				init/init_structs.c		 \
				utils/ft_free.c				\
				pars/pars.c				\
				pars/pars_utils.c	\
				pars/check_map.c	\
				pars/check_map_utils.c \
				pars/check_map_content.c \
				pars/get_path_texture.c  \
				raycasting/move.c \
				raycasting/move_1.c  \
				raycasting/raycasting.c \
				raycasting/texture_ray.c \

				
OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
MLX		= libmlx.a
LIBFT	= libft.a
LFLAGS	= -I include/
CFLAGS = -Wall -Wextra -Werror -g
DEBUGGING = -ggdb
CC = gcc
RM = rm -rf
AR = ar rc

all: objects libft minilibx $(NAME)

libft:
	make -C libft/
minilibx:
	make -C mlx/
objects:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/pars
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/init
	@mkdir -p $(OBJ_DIR)/raycasting



$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) libft/$(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -g

clean:
		make -C mlx clean
		make -C libft clean
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

leak:	all
	leaks -atExit -- ./$(NAME) testing_files/small.cub

.PHONY: all clean re fclean

