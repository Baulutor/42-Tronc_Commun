# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 12:59:41 by eslamber          #+#    #+#              #
#    Updated: 2023/02/20 15:51:00 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Definitions of variables
#

# Definitions of compilation options
FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
CC := gcc

# Definition of variable librairie
LIB := lib_str.a

LIB_STR_SRC := src/
LIB_STR_OBJ := obj/

# Definition of variables needed to librairie's compilation

STR_LIB := ft_atoi.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_split.c \
		   ft_strdup.c \
		   ft_strjoin.c \
		   ft_strlcpy.c \
		   ft_strmapi.c \
		   ft_strnstr.c \
		   ft_strtrim.c \
		   ft_tolower.c \
		   ft_in.c \
		   ft_isalpha.c \
		   ft_isdigit.c \
		   ft_itoa.c \
		   ft_strchr.c \
		   ft_striteri.c \
		   ft_strlcat.c \
		   ft_strlen.c \
		   ft_strncmp.c \
		   ft_strrchr.c \
		   ft_substr.c \
		   ft_toupper.c \
		   ft_calloc_str.c \
		   get_next_line_utils.c \
		   get_next_line.c
STR_LIB_H := $(LIB_STR)lib_str.h \
			 $(LIB_STR)lib_str.h
STR_OBJ_LIB := $(STR_LIB:%.c=$(LIB_STR_OBJ)%.o)

# Definitions of differents printed colors
LIGHTBLUE := '\e[0;32m'
RED := '\e[0;31m'
NEUTRAL := '\e[0m'
#
### Compilations rules
#

all: $(LIB)

$(LIB): $(STR_OBJ_LIB)
	ar rc $@ $^
	ranlib $@

$(STR_OBJ_LIB): $(LIB_STR_OBJ)%.o: $(LIB_STR_SRC)%.c $(STR_LIB_H)
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

make_dir:
	@echo -e $(LIGHTBLUE)make librairies directories$(NEUTRAL)
	mkdir -p $(LIB_STR_OBJ)
	@echo -e $(LIGHTBLUE)done$(NEUTRAL)
	@echo

#
### Prints rules
#

# Compilation of librairie with print options
print: print_ob $(STR_OBJ_LIB) print_lb $(LIB) print_le

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
	@echo -e $(LIGHTBLUE)remove all $(RED)objects files$(NEUTRAL)
	@rm -rfv $(STR_OBJ_LIB)
	@echo

cleanlib: 
	@echo -e $(LIGHTBLUE)remove $(RED)lib file$(NEUTRAL)
	@rm -rfv $(LIB)
	@echo

cleandir: 
	@echo -e $(LIGHTBLUE)remove all $(RED)directories$(NEUTRAL)
	@rm -rfv $(LIB_STR_OBJ)
	@echo

clean_git:
	@echo -e $(LIGHTBLUE)remove all $(RED)gitignore files$(NEUTRAL)
	@rm -rfv ./obj/.gitignore
	@echo

gitignor: 
	@echo -e $(LIGHTBLUE)reediting of differents $(RED)gitignores$(NEUTRAL)
	touch ./obj/.gitignore
	@echo "*" > ./obj/.gitignore
	@echo !.gitignore >> ./obj/.gitignore
	@echo

# Full cleaning rules
fclean: clean cleanlib clean_git cleandir make_dir gitignor

# Remake rules
re: fclean all

re_deb: fclean debug

re_val: fclean valgrind_deb

# Remakes rules with print options
reprint: fclean print

.PHONY: all make_dir print print_ob print_oe print_lb print_le clean cleandir
.PHONY: clean_git gitignor flcean re reprint cleanlib debug valgrind_deb re_deb
.PHONY: re_val
