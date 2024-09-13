# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:02:28 by psanguna          #+#    #+#              #
#    Updated: 2024/08/01 18:18:28 by psangunna        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -f

NAME = libft.a
HEADER_FILE = libft.h
SOURCE_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
	       ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
	       ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	       ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
	       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line_bonus.c\
	       get_next_line_utils_bonus.c 

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
	      ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
	      ft_lstmap_bonus.c

O_BONUS_FILES = $(BONUS_FILES:.c=.o)
BONUS_CACHE = .cache

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	@$(LIB) $(NAME) $(OBJECT_FILES)

$(BONUS_CACHE):$(O_BONUS_FILES)
	@$(LIB) $(NAME) $(O_BONUS_FILES)
	@touch $(BONUS_CACHE)

bonus:$(BONUS_CACHE)

clean:
	$(RM) $(OBJECT_FILES) $(O_BONUS_FILES) $(BONUS_CACHE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
