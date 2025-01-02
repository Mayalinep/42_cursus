# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 19:27:03 by mpelage           #+#    #+#              #
#    Updated: 2025/01/02 15:05:33 by mpelage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme final
NAME = push_swap

# Répertoires
SRC_DIR = ./src
INCLUDE_DIR = ./include
PRINTF_DIR = ./ft_printf
LIBFT_DIR = $(PRINTF_DIR)/libft

# Fichiers sources
SRC_FILES = error.c libft_mod.c push_swap.c utils.c pswap.c rot_rswap.c rswap.c sswap.c sorting.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Commandes
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

# Cible principale
all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)       # Compile libft.a
	make -C $(PRINTF_DIR)      # Compile ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
