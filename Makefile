# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmanu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 19:24:44 by migmanu           #+#    #+#              #
#    Updated: 2023/10/10 18:54:55 by migmanu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
SRCS_DIR = ./src/
SRCS = main.c

OBJ_FILES = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# GNL
GNL_DIR = ./get_next_line/
GNL = 	get_next_line.c \
		get_next_line_utils.c \

GNL_OBJS = ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}

# LIBFT
LIBFT_DIR = ./libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a

# MLX42
MLX42_DIR = MLX42/build
MLX42_PATH = $(MLX42_DIR)/libmlx42.a

# LIBRARIES
INCLUDE_DIRS = -I$(LIBFT_DIR) -I$(MLX42_DIR)/include
LDFLAGS = -L$(LIBFT_DIR) -lft
CFLAGS = -Wall -Werror -Wextra -g $(INCLUDE_DIRS) -ldl -lglfw -pthread -lm

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

all: ${NAME}

$(NAME): $(OBJ_FILES) $(GNL_OBJS) $(LIBFT_PATH) $(MLX42_PATH)
	@echo $(CYAN) "Compiling $@...🛠️"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(GNL_OBJS) $(LDFLAGS) $(MLX42_PATH)
	@echo $(GREEN) "OK COMPILED"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo $(RED) "Cleaning..." $(EOC)
	@$(RM) $(OBJ_FILES) $(GNL_OBJS)

fclean: clean
	@echo $(PURPLE) "Full Cleaning...🧹" $(EOC)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean

