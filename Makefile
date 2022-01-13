# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 13:24:00 by egomez-a          #+#    #+#              #
#    Updated: 2022/01/13 12:07:47 by egomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
SRCS_DIR	= sources/
OBJ_DIR		= obj/
INC_DIR		= include/
LIBFT		= libft.a
LIBFT_DIR	= libft/
MLX			= libmlx.a
MLX_DIR		= mlx/

SRCS 		= 	main.c \
				map2d.c \
				checkmap.c \
				get_next_line.c \
				window.c \
				draw.c \
				hooks.c \
				moves_ud.c \
				moves_lr.c \
				error.c \

OBJS 		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEBUGGING	= -g3 -fsanitize=address -O0
LFLAGS		= -I$(INC_DIR)
RM			= rm -rf
NORM		= /usr/bin/norminette
MFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit 
NOW			= $(shell date +"%d-%m-%y %H:%M")

NONE		=	'\033[0m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[0;33m'
BLUE		=	'\033[0;34m'
PURPLE		=	'\033[0;35m'

all: ${NAME}

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(LFLAGS) $< -o $@

$(NAME): $(OBJS)
	@cd $(MLX_DIR) make
	@echo $(YELLOW) "==== Compilation of Libft and Minilibx Libraries==== " $(NONE)
	make -C $(LIBFT_DIR)
	${CC} $(CFLAGS) $(LFLAGS) $(MFLAGS) $(MLX_DIR)$(MLX) $(LIBFT_DIR)$(LIBFT) -o $(NAME) $(OBJS)
	@echo $(GREEN) "======== COMPILED  ==========" $(NONE)

clean:
		@echo $(YELLOW) "========== CLEAN ==========" $(NONE)
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		make -C $(LIBFT_DIR) clean
		@echo $(GREEN) "=========== DONE ===========" $(NONE)
		
fclean: clean
		@echo $(PURPLE) "========== FCLEAN ==========" $(NONE)
		$(RM) $(NAME)
		make -C $(LIBFT_DIR) fclean
		@echo $(GREEN) "=========== DONE ===========" $(NONE)

re: 	fclean all

git: fclean
	@echo $(BLUE) "===== PUSHING to GITHUB ===="  $(NONE)
	git add .
	git commit -m "so_long - $(NOW)"
	git push origin master
	@echo $(GREEN)"=============== DONE ================"$(NONE)

norm: 
		$(NORM) $(SRC);

#Regla para evitar que usemos estas palabras 
.PHONY:		all, clean, fclean, re