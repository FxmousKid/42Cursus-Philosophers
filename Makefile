# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 19:41:21 by inazaria          #+#    #+#              #
#    Updated: 2024/07/19 16:35:02 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories & Files
SRC_DIR = ./src/
BUILD_DIR = ./build/
INC_DIR = ./includes/

SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRC_FILES))
DEP_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.d, $(SRC_FILES))


# Variables
NAME := philo
CC := clang
CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR) -MMD -MP
RM := rm -f

# Modifying Implicit conversion rules
$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@ 

# This is to add the .d files as dependencies for linking
-include $(DEP_FILES)


# Rules
all : $(NAME)

re : fclean $(NAME)

$(NAME) : $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean : 
	@$(shell $(RM) $(DEP_FILES) $(OBJ_FILES))

fclean : 
	@$(shell $(RM) $(DEP_FILES) $(OBJ_FILES) $(NAME))
