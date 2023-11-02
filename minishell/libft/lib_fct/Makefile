# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 12:35:34 by eslamber          #+#    #+#              #
#    Updated: 2023/02/20 15:49:00 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Definitions of variables
#

# Definitions of compilation options
FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
CC := gcc

# Definition of variable librairie
LIB := lib_fct.a

# Definitions of librairies repositories
LIB_MATH := lib_math/
LIB_MATH_SRC := $(LIB_MATH)src/
LIB_MATH_OBJ := $(LIB_MATH)obj/

LIB_PRINT := lib_print/
LIB_PRINT_SRC := $(LIB_PRINT)src/
LIB_PRINT_OBJ := $(LIB_PRINT)obj/

LIB_MEM := lib_mem/
LIB_MEM_SRC := $(LIB_MEM)src/
LIB_MEM_OBJ := $(LIB_MEM)obj/

LIB_STR := lib_str/
LIB_STR_SRC := $(LIB_STR)src/
LIB_STR_OBJ := $(LIB_STR)obj/

ALL_LIB_OBJ_DIR := $(LIB_MATH_OBJ) \
				   $(LIB_PRINT_OBJ) \
				   $(LIB_MEM_OBJ) \
				   $(LIB_STR_OBJ)

ALL_LIB_SRC_DIR := $(LIB_MATH_SRC) \
				   $(LIB_PRINT_SRC) \
				   $(LIB_MEM_SRC) \
				   $(LIB_STR_SRC)

# Definition of variables needed to librairie's compilation
MATH_LIB := ft_power.c \
			ft_max.c
MATH_LIB_H := $(LIB_MATH)lib_math.h
MATH_OBJ_LIB := $(MATH_LIB:%.c=$(LIB_MATH_OBJ)%.o)

MEM_LIB := ft_bzero.c \
		   ft_calloc.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_memset.c
MEM_LIB_H := $(LIB_MEM)lib_mem.h
MEM_OBJ_LIB := $(MEM_LIB:%.c=$(LIB_MEM_OBJ)%.o)

PRINT_LIB := ft_putchar_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_putstr_fd.c \
			 ft_printf.c \
			 ft_printf_fd.c \
			 conv_ten_to_hex.c
PRINT_LIB_H := $(LIB_PRINT)lib_print.h
PRINT_OBJ_LIB := $(PRINT_LIB:%.c=$(LIB_PRINT_OBJ)%.o)

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
			 $(LIB_STR)get_next_line.h
STR_OBJ_LIB := $(STR_LIB:%.c=$(LIB_STR_OBJ)%.o)

ALL_OBJ_LIB := $(MATH_OBJ_LIB) \
			   $(MEM_OBJ_LIB) \
			   $(PRINT_OBJ_LIB) \
			   $(STR_OBJ_LIB)

# Definitions of differents printed colors
LIGHTBLUE := '\e[0;32m'
RED := '\e[0;31m'
NEUTRAL := '\e[0m'
#
### Compilations rules
#

all: $(LIB)

$(LIB): $(ALL_OBJ_LIB)
	ar rc $@ $^
	ranlib $@

$(MATH_OBJ_LIB): $(LIB_MATH_OBJ)%.o: $(LIB_MATH_SRC)%.c $(MATH_LIB_H) lib_fct.h
	$(CC) $(FLAGS) -c $< -o $@

$(MEM_OBJ_LIB): $(LIB_MEM_OBJ)%.o: $(LIB_MEM_SRC)%.c $(MEM_LIB_H) lib_fct.h
	$(CC) $(FLAGS) -c $< -o $@

$(PRINT_OBJ_LIB): $(LIB_PRINT_OBJ)%.o: $(LIB_PRINT_SRC)%.c $(PRINT_LIB_H) \
	lib_fct.h
	$(CC) $(FLAGS) -c $< -o $@

$(STR_OBJ_LIB): $(LIB_STR_OBJ)%.o: $(LIB_STR_SRC)%.c $(STR_LIB_H) lib_fct.h
	$(CC) $(FLAGS) -c $< -o $@

$(GNL_OBJ_LIB): $(LIB_GNL_OBJ)%.o: $(LIB_GNL_SRC)%.c $(GNL_LIB_H) lib_fct.h
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
	mkdir -p $(ALL_LIB_OBJ_DIR)
	@echo -e $(LIGHTBLUE)done$(NEUTRAL)
	@echo

#
### Prints rules
#

# Compilation of librairie with print options
print: print_ob $(ALL_OBJ_LIB) print_lb $(LIB) print_le

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
	@rm -rfv $(ALL_OBJ_LIB)
	@echo

cleanlib: 
	@echo -e $(LIGHTBLUE)remove $(RED)lib file$(NEUTRAL)
	@rm -rfv $(LIB)
	@echo

cleandir: 
	@echo -e $(LIGHTBLUE)remove all $(RED)directories$(NEUTRAL)
	@rm -rfv $(ALL_LIB_OBJ_DIR)
	@echo

clean_git:
	@echo -e $(LIGHTBLUE)remove all $(RED)gitignore files$(NEUTRAL)
	@rm -rfv ./*/obj/.gitignore
	@echo

gitignor: 
	@echo -e $(LIGHTBLUE)reediting of differents $(RED)gitignores$(NEUTRAL)
	touch ./lib_math/obj/.gitignore
	@echo "*" > ./lib_math/obj/.gitignore
	@echo !.gitignore >> ./lib_math/obj/.gitignore
	cp ./lib_math/obj/.gitignore ./lib_print/obj
	cp ./lib_math/obj/.gitignore ./lib_str/obj
	cp ./lib_math/obj/.gitignore ./lib_mem/obj
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
.PHONY: clean_git gitignor flcean re reprint clean_lib debug valgrind_deb re_deb
.PHONY: re_val
