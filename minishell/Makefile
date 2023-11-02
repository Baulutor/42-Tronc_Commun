# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:30:03 by eslamber          #+#    #+#              #
#    Updated: 2023/10/30 17:23:35 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Definitions of variables
#

# Compilation flags
FLAGS := -Wall -Werror -Wextra
CC := gcc

#
### Definition of variables
#

# Definition of lib
LIB := libft/libft.a
INC := -Ilibft
LIBRAIRIE := -lreadline

# Definition of project variables
NAME := minishell
REPO_HEADER := incs/
HEADER := $(REPO_HEADER)minishell.h

# Definitions of differents repos
PARS := parsing/
ECHO := builtins/echo/
BUILTINS := builtins/
EXP := builtins/export/
VERIF := verif_read/
ENV := environement/
PREP := prep_heredoc/
RED := redirection/check_redirection/
RED_PAR := redirection/check_redirection_parent/
HIST := historic/
EXPAND := expand/
EXEC := execution_center/
FOR_EXEC := execution_center/for_exec/
ERR_FREE := error_and_free/
SIGNAL := signals/
UNSET := builtins/unset/

# Definition of files variables
SRC := main.c \
	   minishell_utils.c \
	   $(UNSET)unset.c \
	   $(SIGNAL)signals.c \
	   $(SIGNAL)signals_handler.c \
	   $(ERR_FREE)free_struc.c \
	   $(ERR_FREE)error.c \
	   $(FOR_EXEC)cmd_build.c \
	   $(FOR_EXEC)cmd_center_simple.c \
	   $(HIST)historic.c \
	   $(PARS)parsing.c \
	   $(PARS)parse_arguments.c \
	   $(PARS)parsing_count_arg.c \
	   $(PARS)parsing_count_caractere.c \
	   $(VERIF)verif_read.c \
	   $(VERIF)verif_read_utils_bis.c \
	   $(VERIF)verif_read_utils.c \
	   $(VERIF)trash_quote_buil_exec.c \
	   $(BUILTINS)builtins_utils.c \
	   $(BUILTINS)search_builtins.c \
	   $(BUILTINS)builtins_parent.c \
	   $(BUILTINS)builtins.c \
	   $(BUILTINS)builtins_utils_bis.c \
	   $(BUILTINS)search_builtins_parent.c \
	   $(EXEC)execution_center.c \
	   $(EXEC)execution_center_utils.c \
	   $(EXEC)pipe.c \
	   $(RED)check_redirection.c \
	   $(RED)duplication.c \
	   $(RED)check_red_utils.c \
	   $(RED_PAR)check_redirection_parent.c \
	   $(RED_PAR)search_open_file.c \
	   $(RED_PAR)initialise_redir_parent.c \
	   $(RED_PAR)here_doc_check_redir.c \
	   $(PREP)prep_heredoc.c \
	   $(PREP)prep_heredoc_utils.c \
	   $(PREP)handle_history.c \
	   $(ENV)environement.c \
	   $(ENV)exp_env.c \
	   $(EXP)export.c \
	   $(EXP)add_exp_env.c \
	   $(EXP)check_if_replace_env.c \
	   $(EXP)check_if_replace_exp_env.c \
	   $(EXP)export_utils.c \
	   $(EXPAND)expand.c \
	   $(EXPAND)add_var_to_sentence.c \
	   $(EXPAND)expand_utils.c \
	   $(ECHO)echo.c \
	   $(ECHO)echo_utils.c
OBJ := $(SRC:%.c=.obj/%.o)

#
### Compilation rules
#

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ -L. $(LIB) $(LIBRAIRIE)

.obj/$(PARS)%.o: $(PARS)%.c $(REPO_HEADER)parsing.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(EXP)%.o: $(EXP)%.c $(REPO_HEADER)export.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(VERIF)%.o: $(VERIF)%.c $(REPO_HEADER)verif_read.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(ENV)%.o: $(ENV)%.c $(REPO_HEADER)environement.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(ECHO)%.o: $(ECHO)%.c $(REPO_HEADER)echo.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(BUILTINS)%.o: $(BUILTINS)%.c $(REPO_HEADER)builtins.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)
	
.obj/$(PREP)%.o: $(PREP)%.c $(REPO_HEADER)prep_heredoc.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(HIST)%.o: $(HIST)%.c $(REPO_HEADER)historic.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(RED)%.o: $(RED)%.c $(REPO_HEADER)check_redirection.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(RED_PAR)%.o: $(RED_PAR)%.c $(REPO_HEADER)check_redirection_parent.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(EXPAND)%.o: $(EXPAND)%.c $(REPO_HEADER)expand.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(EXEC)%.o: $(EXEC)%.c $(REPO_HEADER)execution_center.h $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(FOR_EXEC)%.o: $(FOR_EXEC)%.c $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/$(ERR_FREE)%.o: $(ERR_FREE)%.c $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

.obj/%.o: %.c $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ $(LIBRAIRIE)

$(LIB): FORCE
	make -C libft

# Debug
debug:
	make -C libft debug
	make -C ./ "FLAGS = -Wall -Wextra -fsanitize=address \
	-fno-omit-frame-pointer -g3"

val_deb:
	make -C libft valgrind_deb
	make -C ./ "FLAGS = -Wall -Werror -Wextra -g3"

#
### Cleanup rules
#

clean:
	@rm -rfv $(OBJ) $(OBJ_B)
	make -sC libft clean

fclean:
	@rm -rfv $(OBJ) $(OBJ_B) $(NAME)
	make -sC libft fclean

re: fclean all

re_deb: fclean debug

re_val: fclean val_deb

FORCE:

.PHONY: all clean fclean re FORCE debug re_deb val_deb re_val
