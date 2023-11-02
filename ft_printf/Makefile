# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 12:12:48 by dbaule            #+#    #+#              #
#    Updated: 2022/11/23 13:34:35 by dbaule           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= libftprintf.a
INCS		:= ft_printf.h

SRCS		:= ft_printchar.c \
			   ft_printf.c	\
			   ft_printstr.c\
			   ft_printint.c\
			   ft_printunsignedint.c\
			   ft_printhexamin.c\
			   ft_printhexamaj.c\
			   ft_printaddress.c\

OBJS		:= $(SRCS:%.c=%.o)

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

$(NAME): $(OBJS) 
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo " Done!"

$(OBJS): %.o:%.c ${INCS} Makefile
	@echo " compiling: $<"
	@$(CC) $(CC_FLAGS) -I. -c $< -o $@

# clean commands
clean:
	@echo "remove all objects files"
	@rm -rf *.o
	@echo "${GREEN}> Clean${RESET}"

fclean: clean
	@echo "remove $(NAME)"
	@rm -rf $(NAME)

re: fclean all

# utility
norm:
	@echo "${LIGHTPURPLE}> Norminette Libft${RESET}"
	@norminette -R CheckDefine $(SRCS)

.PHONY: all clean fclean re norm print_clean bonus
