# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 15:13:22 by dbaule            #+#    #+#              #
#    Updated: 2023/01/11 13:59:49 by dbaule           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= libft.a
INCS		:= libft.h

SRCS		:= ft_isalpha.c \
			   ft_isdigit.c \
			   ft_isalnum.c \
			   ft_isascii.c \
			   ft_isprint.c \
			   ft_toupper.c \
			   ft_tolower.c \
			   ft_atoi.c \
			   ft_strdup.c \
			   ft_strchr.c \
			   ft_strrchr.c \
			   ft_strlen.c \
			   ft_strlcpy.c \
			   ft_strlcat.c \
			   ft_strncmp.c \
			   ft_strnstr.c \
			   ft_substr.c \
			   ft_strjoin.c \
			   ft_strtrim.c \
			   ft_split.c \
			   ft_itoa.c \
			   ft_strmapi.c \
			   ft_striteri.c \
			   ft_calloc.c \
			   ft_bzero.c \
			   ft_memset.c \
			   ft_memcpy.c \
			   ft_memmove.c \
			   ft_memchr.c \
			   ft_memcmp.c \
			   ft_putchar_fd.c \
			   ft_putstr_fd.c \
			   ft_putendl_fd.c \
			   ft_putnbr_fd.c

OBJS		:= $(SRCS:%.c=%.o)

OBJS_BONUS	:= $(SRCS_BONUS:%.c=%.o)

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

bonus:	$(OBJS) $(OBJS_BONUS)
	@ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	@ranlib $(NAME)
	@echo " Bonus Done!"

$(OBJS_BONUS):%.o:%.c
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
	@norminette -R CheckDefine $(SRCS) $(SRCS_BONUS)

.PHONY: all clean fclean re norm print_clean bonus
