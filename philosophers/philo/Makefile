# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 10:54:41 by dbaule            #+#    #+#              #
#    Updated: 2023/11/14 11:54:09 by dbaule           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#
### Definitions of variables
#

# Compilation flags
FLAGS := -Wall -Werror -Wextra -pthread
CC := gcc

#
### Definition of variables
#

# Definition of lib
# LIB := libft/libft.a
# INC := -Ilibft

# Definition of project variables
NAME := philo
HEADER := philo.h \

# Definition of files variables
SRC := main.c \
	   philo_utils.c \
	   error.c \
	   parsing.c \
	   init.c \
	   exec.c \
	   events.c \
	   eating.c \
	   print.c \
	   philo_utils_lib.c \
	   loop_thread.c \

OBJ := $(SRC:%.c=.obj/%.o)

# Definition of bonus files variables

#
### Compilation rules
#

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ -L. 

.obj/%.o: %.c $(HEADER) 
	$(CC) $(FLAGS) $(INC) -c $< -o $@

# Debug
debug:
	make -C ./ "FLAGS = -Wall -Werror -Wextra -fsanitize=thread -pthread -g"

val_deb:
	make -C ./ "FLAGS = -Wall -Werror -Wextra -g"

#
### Cleanup rules
#

clean:
	rm -rfv $(OBJ)

fclean:
	rm -rfv $(OBJ) $(NAME)

re: fclean all

re_deb: fclean debug

re_val: fclean val_deb

FORCE:

.PHONY: all clean fclean re FORCE debug re_deb val_deb re_val bonus re_bonus 
.PHONY: re_bonus_deb
