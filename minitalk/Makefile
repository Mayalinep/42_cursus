# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 17:26:17 by mpelage           #+#    #+#              #
#    Updated: 2024/12/28 22:03:39 by mpelage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables générales
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# Noms des exécutables
SERVER = server
CLIENT = client

# Dossiers et chemins d’inclusion
INCLUDES = -I ./ -I ./gnl -I ./gnl/source -I ./ft_printf/libft -I ./ft_printf

# Fichiers sources
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c
SRCS_GNL = gnl/source/get_next_line.c gnl/source/get_next_line_utils.c
SRCS_PRINTF = ft_printf/ft_printf.c ft_printf/ft_print_base10.c ft_printf/ft_print_base16.c \
              ft_printf/ft_print_hexa.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

# Bibliothèque de la libft
LIBFT_LIB = ft_printf/libft/libft.a

# Règle principale
all: $(LIBFT_LIB) $(SERVER) $(CLIENT)

# Compilation du serveur
$(SERVER): $(OBJS_SERVER) $(OBJS_GNL) $(OBJS_PRINTF) $(LIBFT_LIB)
	@echo "\033[1;32mCompiling $(SERVER)...\033[m"
	$(CC) $(CFLAGS) $(INCLUDES) -o $(SERVER) $(OBJS_SERVER) $(OBJS_GNL) $(OBJS_PRINTF) $(LIBFT_LIB)

# Compilation du client
$(CLIENT): $(OBJS_CLIENT) $(OBJS_GNL) $(OBJS_PRINTF) $(LIBFT_LIB)
	@echo "\033[1;32mCompiling $(CLIENT)...\033[m"
	$(CC) $(CFLAGS) $(INCLUDES) -o $(CLIENT) $(OBJS_CLIENT) $(OBJS_GNL) $(OBJS_PRINTF) $(LIBFT_LIB)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Générer la bibliothèque libft
$(LIBFT_LIB):
	@echo "\033[1;33mBuilding libft library...\033[m"
	$(MAKE) -C ft_printf/libft

# Nettoyer les fichiers objets
clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_GNL) $(OBJS_PRINTF)
	@echo "\033[1;34mCleaning object files...\033[m"
	$(MAKE) -C ft_printf/libft clean

# Nettoyage complet
fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	@echo "\033[1;34mRemoving executables...\033[m"
	$(MAKE) -C ft_printf/libft fclean

# Recompiler à partir de zéro
re: fclean all

# Commandes spéciales pour Makefile
.PHONY: all clean fclean re
