# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 15:13:22 by dbaule            #+#    #+#              #
#    Updated: 2023/05/03 18:12:22 by dbaule           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		:= push_swap
INCS		:= push_swap.h

SRCS		:=	command_swap_push_a.c \
				command_swap_push_b.c \
				command_swap_push.c \
				error_check_initialise.c \
				manage_error.c \
				free.c \
				linked_list.c \
				push_swap_utils.c \
				push_swap.c \
				sort_small_stack.c \
				sort.c \
				sort_five_and_four_stack.c \

OBJS		:= $(SRCS:%.c=%.o)

# Others makefile remaining for the compilation

DIR_FT_PRINTF	= ft_printf/
FT_PRINTF		= $(addprefix $(DIR_FT_PRINTF), libftprintf.a)

DIR_LIBFT	= libft/
LIBFT		= $(addprefix $(DIR_LIBFT), libft.a)

# Compiler options
CC			:= cc
CC_FLAGS	:= -Wall -Wextra -Werror

# define standard colors
BLACK		:= $(shell tput -Txterm setaf 0)
RED			:= $(shell tput -Txterm setaf 1)
GREEN		:= $(shell tput -Txterm setaf 2)
YELLOW		:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
PURPLE		:= $(shell tput -Txterm setaf 5)
BLUE		:= $(shell tput -Txterm setaf 6)
WHITE		:= $(shell tput -Txterm setaf 7)
RESET		:= $(shell tput -Txterm sgr0)

#########################
# 		RULES			#
#########################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	@echo ${YELLOW}"\nDone!"
	@$(CC) $(CC_FLAGS) -I. $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME) 

$(OBJS): %.o:%.c ${INCS}
	@echo " compiling: $<"
	@$(CC) $(CC_FLAGS) -I. -c $< -o $@

${FT_PRINTF}:	EXE_FT_PRINTF

${LIBFT}:		EXE_LIBFT

# clean commands
clean:
	@echo "remove all objects files"
	@make clean -s -C ${DIR_FT_PRINTF}
	@make clean -s -C ${DIR_LIBFT}
	@rm -rf *.o
	@echo "${GREEN}> Clean push_swap${RESET}"

fclean: clean
	@echo "remove $(NAME)"
	@make fclean -s -C ${DIR_FT_PRINTF}
	@make fclean -s -C ${DIR_LIBFT}
	@rm -rf $(NAME)

re: fclean all

# utility
norm:
	@make norm -s -C ${DIR_FT_PRINTF}
	@make norm -s -C ${DIR_LIBFT}
	@echo "\n${LIGHTPURPLE}> Norminette push_swap${RESET}"
	@norminette -R CheckDefine $(SRCS) $(INCS)

EXE_FT_PRINTF:
	@make -s -C ${DIR_FT_PRINTF}

EXE_LIBFT: 
	@make -s -C ${DIR_LIBFT}

.PHONY: all clean fclean re norm print_clean EXE_FT_PRINTF EXE_LIBFT
