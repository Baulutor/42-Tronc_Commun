# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 15:13:22 by dbaule            #+#    #+#              #
#    Updated: 2023/06/30 14:17:06 by dbaule           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
BONUS_DIR = ./bonus/
SRCS =	main.c \
		get_next_line.c \
		get_next_line_utils.c \
		fdf_utils.c \
		drawing.c \
		drawing_utils.c \
		ft_split.c \
		free.c \

OBJ_DIR = objs/
OBJ = ${SRCS:%.c=${OBJ_DIR}%.o}
NAME = fdf
RM = rm -f
HEADER = fdf.h
LIBFT = libft/libft.a
LIBFT_DIR = libft/
# --- OS SELECTION --- #

UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		MLX_A	=	${MLX_DIR}libmlx.a
		MLX_DIR	=	minilibx-linux/
		MLX_FLAGS = -lm -L/usr/lib -lXext -lX11
	endif
	# ifeq ($(UNAME_S),Darwin)
	# 	MLX_A	=	${MLX_DIR}libmlx.a
	# 	MLX_DIR	=	mlx/mlx_MAC/
	# 	MLX_FLAGS = -Lmlx/mlx_MAC -lmlx -framework OpenGL -framework AppKit
	# endif

# --- COLORS --- #

_NOC	:=	\033[0m]
_RED	:=	\033[1;31m]
_GREEN	:=	\033[1;32m]

# --- RULES --- #

${NAME} :	${OBJ} ${LIBFT} ${MLX_A} 
		${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${} ${MLX_A} ${MLX_FLAGS} -o ${NAME}
		@echo "${_GREEN}### ${NAME} created ###${_NOC}\n"

${NAME_BONUS} :	${OBJ_BONUS} ${LIBFT} ${MLX_A}
		${CC} ${CFLAGS} ${OBJ_BONUS} ${LIBFT} ${MLX_A} ${MLX_FLAGS} -o ${NAME_BONUS}
		@echo "${_GREEN}### ${NAME_BONUS} created ###${_NOC}\n"

${OBJ}: ${OBJ_DIR}%.o :	%.c ${HEADER} ${LIBFT} ${} ${MLX_A}
		@mkdir -p objs
		${CC} ${CFLAGS} -I/usr/include -I${MLX_DIR} -c $< -o $@

${OBJ_BONUS}: ${OBJ_DIR}%.o :	${BONUS_DIR}%.c ${HEADER_BONUS} ${LIBFT} ${MLX_A}
		@mkdir -p objs
		${CC} ${CFLAGS} -I/usr/include -I${MLX_DIR} -c $< -o $@

${LIBFT}: FORCE
		${MAKE} -sC ${LIBFT_DIR}

${MLX_A}: FORCE
		@${MAKE} -sC ${MLX_DIR}


FORCE:

all :	${NAME}

bonus :	${NAME_BONUS}

clean :
		@${MAKE} clean -sC ${LIBFT_DIR}
		@${MAKE} clean -sC ${MLX_DIR}
		rm -rf objs/
		@echo "${_RED}### Removed FdF object files ###${_NOC}"

fclean :	clean
		@${MAKE} fclean -sC ${LIBFT_DIR}
		${RM} ${NAME} ${NAME_BONUS}
		@echo "${_RED}### Removed ${NAME} and/or ${NAME_BONUS} ###${_NOC}"

re : 	fclean all

.PHONY : all clean fclean re FORCE bonus