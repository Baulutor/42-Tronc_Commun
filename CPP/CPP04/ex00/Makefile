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



NAME            	=  	Animal

HEADERS_FILES    	=  	Animal.hpp \
						Cat.hpp \
						Dog.hpp \
						WrongAnimal.hpp \
						WrongCat.hpp

HEADERS            	=   $(HEADERS_FILES)

SRC_FILES        	=  	main.cpp \
 						Animal.cpp \
 						Cat.cpp \
 						Dog.cpp \
 						WrongAnimal.cpp \
 						WrongCat.cpp

SRCS            	=  	$(SRC_FILES)

DIRECTORY        	=   .obj
OBJS            	=   $(SRC_FILES:%.cpp=$(DIRECTORY)/%.o)

CC                	=   c++
CC_FLAGS        	=   -Wextra -Werror -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

$(DIRECTORY)/%.o:  %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(DIRECTORY)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re