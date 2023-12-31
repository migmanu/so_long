# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmanu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 19:24:44 by migmanu           #+#    #+#              #
#    Updated: 2023/10/25 16:28:26 by jmigoya-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
SRCS_DIR = ./src/
SRCS = main.c \
       00_build_map/build_map.c \
       01_check_map/map_parse.c \
       01_check_map/map_flood.c \
       10_error_handling/handle_error.c \
	   02_fill_map/fill_map.c \
	   02_fill_map/fill_map_utils.c \
	   02_fill_map/load_assets.c \
	   02_fill_map/load_assets_utils.c \
	   03_move_character/move_character.c \
	   03_move_character/movements.c \

OBJ_FILES = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

# GNL
GNL_DIR = ./get_next_line/
GNL = get_next_line.c \
      get_next_line_utils.c

GNL_OBJS = $(addprefix $(GNL_DIR), $(GNL:.c=.o))

# LIBFT
LIBFT_DIR = ./libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a

# MLX42
MLX42_DIR = ./MLX42
MLX42_PATH = $(MLX42_DIR)/build/libmlx42.a

# LIBRARIES
INCLUDE_DIRS = -I ./include -I $(LIBFT_DIR) -I $(MLX42_DIR)/include
CFLAGS = -Wall -Werror -Wextra -g $(INCLUDE_DIRS)
LDFLAGS = -L$(LIBFT_DIR) -lft
MFLAGS = $(MLX42_PATH) -Iinclude -ldl -lglfw -pthread -lm

# COMPILATION
NAME = so_long
CC = cc
RM = rm -f

# COLORS
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all: $(NAME)

$(NAME): $(OBJ_FILES) $(GNL_OBJS) $(LIBFT_PATH) $(MLX42_PATH)
	@echo $(CYAN) "Compiling $@...🛠️"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(GNL_OBJS) $(LDFLAGS) $(MFLAGS)
	@echo $(GREEN) "OK COMPILED"

%.o: %.c
	@git submodule update --init
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
	@$(MAKE) -C $(LIBFT_DIR) -s

$(MLX42_PATH):
	@cmake -B $(MLX42_DIR)/build $(MLX42_DIR)
	@cmake --build $(MLX42_DIR)/build -j4

clean:
	@echo $(RED) "Cleaning..." $(EOC)
	@make clean -C $(LIBFT_DIR) -s
	@$(RM) $(OBJ_FILES) $(GNL_OBJS)

fclean: clean
	@echo $(PURPLE) "Full Cleaning...🧹" $(EOC)
	@make fclean -C $(LIBFT_DIR) -s
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean

