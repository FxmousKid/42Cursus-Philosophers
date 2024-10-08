# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 19:41:21 by inazaria          #+#    #+#              #
#    Updated: 2024/09/20 19:07:54 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<><><><><><><> Files <><><><><><><><><><><><><><><><><><><>
SRC_DIR 	= ./src/

BUILD_DIR 	= ./build/
INC_DIR 	= ./includes/

DEBUG_FILE_PATH = ./src/error_manager/debugging_functions
DEBUG_BUILD_PATH = ./build/error_manager/debugging_functions

# .c files for source code
SRC_FILES_NAMES = main.c
SRC_FILES_NAMES += simulate_philo_life.c
SRC_FILES_NAMES += utils/helper_functions.c
SRC_FILES_NAMES += utils/init_philosophers.c
SRC_FILES_NAMES += error_manager/error_manager.c
SRC_FILES_NAMES += error_manager/destroy_philosophers.c


# Full path to .c files
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC_FILES_NAMES))

# .o files for compilation
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRC_FILES))

# .d files for header dependency
DEP_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.d, $(SRC_FILES))


#<><><><><><><> Variables <><><><><><><><><><><><><><><><><>

NAME := philo
CC := clang
CFLAGS := -g3 -Wall -Wextra -Werror -I $(INC_DIR) -MMD -MP
MKDIR := mkdir -p
RM_RF := rm -rf

BLUE	:= $(shell echo -e "\033[34m") 
BROWN	:= $(shell echo -e "\033[33m")
GREEN	:= $(shell echo -e "\033[32m")
NC		:= $(shell echo -e "\033[0m")
RED		:= $(shell echo -e "\033[31m")

#<><><><><><><> Recipes <><><><><><><><><><><><><><><><><><>

# Modifying Implicit conversion rules to build in custom directory
$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@$(MKDIR) $(dir $@)
	@echo -e "$(BLUE)[CMP] Compiling $<...$(NC)"
	@$(CC) -c $(CFLAGS) $< -o $@ 


# This is to add the .d files as dependencies for linking
-include $(DEP_FILES) $(DEBUG_BUILD_PATH).d


re : clean all


$(NAME) : $(OBJ_FILES)
	@echo -e "$(BROWN)[BLD] Building Philosopher executable...$(NC)"
	@$(RM) $(DEBUG_BUILD_PATH).[od]
	@$(RM) $(NAME)
	@$(CC) $(CFLAGS) -c $(DEBUG_FILE_PATH).c -o $(DEBUG_BUILD_PATH).o
	@$(CC) $(CFLAGS) $^ $(DEBUG_BUILD_PATH).o -o $(NAME)
	@echo -e "$(GREEN)[BLD] Executable built successfully.$(NC)"

all : $(NAME) 

debug : $(OBJ_FILES)
	@echo -e "$(RED)[DBG] Making in DEBUG MODE...$(NC)"
	@$(RM) $(DEBUG_BUILD_PATH)
	@$(CC) $(CFLAGS) -D DEBUG -c $(DEBUG_FILE_PATH).c -o $(DEBUG_BUILD_PATH).o
	@echo -e "$(BROWN)[BLD] Building executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(DEBUG_BUILD_PATH).o -o $(NAME)
	@echo -e "$(GREEN)[BLD] Executable built successfully.$(NC)"

clean : 
	@echo -e "$(BROWN)[CLN] Cleaning object and dependency files...$(NC)"
	@$(RM) $(DEP_FILES) $(OBJ_FILES) $(DEBUG_BUILD_PATH).[od]
	@echo -e "$(GREEN)[CLN] Clean complete.$(NC)"

fclean : 
	@echo -e "$(BROWN)[CLN] Cleaning object, dependency files, and executable...$(NC)"
	@$(RM_RF) $(BUILD_DIR) $(NAME)
	@echo -e "$(GREEN)[CLN] Clean complete.$(NC)"


.DEFAULT_GOAL := all
.PHONY : all clean fclean re debug
