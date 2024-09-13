# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 18:57:24 by psangunna         #+#    #+#              #
#    Updated: 2024/09/13 18:57:27 by psangunna        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
RM = rm -rf

# Define source files
SRC = main.c utils.c events.c colors.c sets.c # Asegúrate de agregar todos los archivos fuente necesarios

# Define object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Rule to build the main executable
$(NAME): $(OBJ) libft/libft.a minilibx-linux/libmlx.a
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a minilibx-linux/libmlx.a -L/usr/lib -lX11 -lXext -lm -o $(NAME)

# Rule to build the libft library
libft/libft.a:
	make -C libft

# Rule to build the minilibx library
minilibx-linux/libmlx.a:
	make -C minilibx-linux

# Clean object files
clean:
	$(RM) $(OBJ)
	make clean -C libft
	make clean -C minilibx-linux

# Clean everything
fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make clean -C minilibx-linux

# Rebuild everything
re: fclean all
