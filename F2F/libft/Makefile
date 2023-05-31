# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 15:13:22 by dbaule            #+#    #+#              #
#    Updated: 2023/05/31 15:39:59 by dbaule           ###   ########.fr        #
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

SRCS_BONUS :=  ft_lstnew_bonus.c \
			   ft_lstsize_bonus.c \
			   ft_lstclear_bonus.c \
			   ft_lstadd_back_bonus.c \
			   ft_lstadd_front_bonus.c \
			   ft_lstlast_bonus.c \
			   ft_lstdelone_bonus.c \
			   ft_lstiter_bonus.c \
			   ft_lstmap_bonus.c

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

$(OBJS): %.o:%.c ${INCS}
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
	@rm -rf *.o
	@echo "${GREEN}> Clean libft${RESET}"

fclean:
	@rm -rf *.o
	@echo "remove $(NAME)"
	@rm -rf $(NAME)

re: fclean all

# utility
norm:
	@echo "\n${LIGHTPURPLE}> Norminette Libft${RESET}"
	@norminette -R CheckDefine

.PHONY: all clean fclean re norm print_clean bonus
