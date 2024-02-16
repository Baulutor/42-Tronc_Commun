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


NAME            	=  	Fixed

HEADERS_FILES    	=  	Fixed.hpp

HEADERS            	=   $(HEADERS_FILES)

SRC_FILES        	=  	main.cpp \
 						Fixed.cpp

SRCS            	=  	$(SRC_FILES)

BUILD_DIR        	=   .obj
OBJS            	=   $(SRC_FILES:%.cpp=$(BUILD_DIR)/%.o)

CC                	=   c++
CC_FLAGS        	=   -Wextra -Werror -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o:  %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re