# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 19:41:21 by inazaria          #+#    #+#              #
#    Updated: 2024/07/27 00:37:36 by inazaria         ###   ########.fr        #
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

BLUE	:= $(shell echo -e "\033[34m") 
BROWN	:= $(shell echo -e "\033[33m")
GREEN	:= $(shell echo -e "\033[32m")
NC		:= $(shell echo -e "\033[0m")

all : $(NAME)

# Modifying Implicit conversion rules
$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@echo -e "$(BLUE)[CMP] Compiling $<...$(NC)"
	@$(CC) -c $(CFLAGS) $< -o $@ 

# This is to add the .d files as dependencies for linking
-include $(DEP_FILES)

# Rules

re : fclean $(NAME)

$(NAME) : $(OBJ_FILES)
	@echo -e "$(BROWN)[BLD] Building executable...$(NC)"
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo -e "$(GREEN)[BLD] Executable built successfully.$(NC)"

clean : 
	@echo -e "$(BROWN)[CLN] Cleaning object and dependency files...$(NC)"
	@$(RM) $(DEP_FILES) $(OBJ_FILES)
	@echo -e "$(GREEN)[CLN] Clean complete.$(NC)"

fclean : 
	@echo -e "$(BROWN)[CLN] Cleaning object, dependency files, and executable...$(NC)"
	@$(RM) $(DEP_FILES) $(OBJ_FILES) $(NAME)
	@echo -e "$(GREEN)[CLN] Clean complete.$(NC)"


