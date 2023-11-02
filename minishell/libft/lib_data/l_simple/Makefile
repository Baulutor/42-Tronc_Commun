# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:26:23 by eslamber          #+#    #+#              #
#    Updated: 2023/02/20 15:52:58 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definitions of compilation options
FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
CC := gcc

# Definitions of librairies repertories
LIB_SIMPLE_SRC := src/
LIB_SIMPLE_OBJ := obj/

# Definition of variables needed for librairie compilation
LIB := lib_simple.a

SIMPLE_LIB := ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstlast.c \
			  ft_lstmap.c \
			  ft_lstnew.c \
			  ft_lstsize.c
SIMPLE_LIB_H := $(LIB_SIMPLE)lib_simple.h
SIMPLE_OBJ_LIB := $(SIMPLE_LIB:%.c=$(LIB_SIMPLE_OBJ)%.o)

# Definitions of differents printed colors
LIGHTBLUE := '\e[0;32m'
RED := '\e[0;31m'
NEUTRAL := '\e[0m'

# Compilations rules
all: $(LIB)

$(LIB): $(SIMPLE_OBJ_LIB)
	ar rc $@ $^
	ranlib $@

$(SIMPLE_OBJ_LIB): $(LIB_SIMPLE_OBJ)%.o: $(LIB_SIMPLE_SRC)%.c $(SIMPLE_LIB_H)
	$(CC) $(FLAGS) -c $< -o $@

#
### Debug rules
#

debug:
	make -C ./ "FLAGS+= -Wall -Werror -Wextra -fsanitize=address \
	-fno-omit-frame-pointer" print

valgrind_deb:
	make -C ./ "FLAGS+= -Wall -Werror -Wextra -g" print

#
### Directories rules
#

dir:
	@echo -e $(LIGHTBLUE)make librairies directories$(NEUTRAL)
	mkdir -p $(LIB_SIMPLE_OBJ)
	@echo -e $(LIGHTBLUE)done$(NEUTRAL)
	@echo

#
### Print rules
#

# Compilation of librairie with print options
print: print_ob $(SIMPLE_OBJ_LIB) print_lb $(LIB) print_le

print_ob:
	@echo -e $(LIGHTBLUE)compilation lib objects files$(NEUTRAL)

print_oe:
	@echo -e $(LIGHTBLUE)compilation lib objetcs files done$(NEUTRAL)
	@echo

print_lb: print_oe
	@echo -e $(LIGHTBLUE)compilation librairie$(NEUTRAL)

print_le:
	@echo -e $(LIGHTBLUE)compilation librairie done$(NEUTRAL)
	@echo

#
### Cleanup rules
#

# Classiques cleaning rules
clean:
	@echo -e $(LIGHTBLUE)remove all $(RED)librairires objects files$(NEUTRAL)
	@rm -rfv $(SIMPLE_OBJ_LIB)
	@echo

cleanlib: 
	@echo -e $(LIGHTBLUE)remove $(RED)lib file$(NEUTRAL)
	@rm -rfv $(LIB)
	@echo

# Directories cleaning rules
cleandir: 
	@echo -e $(LIGHTBLUE)remove all $(RED)librairies directories$(NEUTRAL)
	@rm -rfv $(LIB_SIMPLE_OBJ)
	@echo

clean_git:
	@echo -e $(LIGHTBLUE)remove all $(RED)gitignore files$(NEUTRAL)
	@rm -rfv /obj/.gitignore
	@echo

gitignor: 
	@echo -e $(LIGHTBLUE)reediting of differents $(RED)gitignores$(NEUTRAL)
	touch ./obj/.gitignore
	@echo "*" > ./obj/.gitignore
	@echo !.gitignore >> ./obj/.gitignore
	@echo

# Full cleaning rules
fclean: clean cleanlib clean_git cleandir dir gitignor

# Remake rules
re: fclean all

re_deb: fclean debug

re_val: fclean valgrind_deb

# Remakes rules with print options
reprint: fclean print

.PHONY: print_oe print_ob print_le print_lb reprint print
.PHONY: re all dir gitignor debug valgrind_deb re_deb re_val
.PHONY: fclean clean cleanlib cleandir clean_git
