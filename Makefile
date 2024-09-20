# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 18:57:24 by psangunna         #+#    #+#              #
#    Updated: 2024/09/16 12:20:49 by psangunna        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
LINK_FLAGS = -lm -lXext -lX11 -lc
RM = rm -rf
DIR_LIBFT = libft/
LIBFT = libft.a
DIR_MINILIBX = minilibx_linux/
MINILIBX = libmlx.a
# Define source files
SRC = fractol.c utils.c events.c colors.c build_julia.c build_mandelbrot.c print_msg.c

# Define object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(LIBFT) $(MINILIBX) $(NAME)

# Rule to build the main executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(DIR_LIBFT)$(LIBFT) $(DIR_MINILIBX)$(MINILIBX) $(LINK_FLAGS) -o $(NAME)

# Rule to build the libft library
$(LIBFT):
	make -C $(DIR_LIBFT)
# Rule to build the minilibx library
$(MINILIBX):
	make -C $(DIR_MINILIBX)
# Clean object files
clean:
	$(RM) $(OBJ)
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_MINILIBX)

# Clean everything
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(DIR_LIBFT)
	make clean -C $(DIR_MINILIBX)

# Rebuild everything
re: fclean all
