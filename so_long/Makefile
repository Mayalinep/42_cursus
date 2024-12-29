# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelage <mpelage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 13:57:56 by mpelage          #+#    #+#              #
#    Updated: 2024/10/22 16:22:19 by mpelage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CCF = clang -Wall -Wextra -Werror -g
FT_PRINTF_PATH = ft_printf/
FT_PRINTF_FILE = libftprintf.a
FT_PRINTF_LIB = $(FT_PRINTF_PATH)$(FT_PRINTF_FILE)

MLX_PATH = minilibx-linux/
MLX_FILE = libmlx.a
MLX_LIB = $(MLX_PATH)$(MLX_FILE)

C_FILE = so_long.c map_parse.c error.c get_next_line.c solong_utils.c flood_fill.c \
		start_mlx.c \

INC = -I ./includes/ \
	-I ./minilibx-linux/

SRC_PATH = ./sources/
SRC = $(addprefix $(SRC_PATH),$(C_FILE))

OBJ = $(SRC:.c=.o)

all: $(FT_PRINTF_LIB) $(MLX_LIB) $(NAME)

$(FT_PRINTF_LIB):
	@echo "COMPILING $(FT_PRINTF_PATH)"
	@make -sC $(FT_PRINTF_PATH)
	@echo "LIBFT_lib created"

$(MLX_LIB):
	@echo "COMPILING $(MLX_PATH)..."
	@make -sC $(MLX_PATH)
	@echo "MLX_lib created"

$(NAME): $(OBJ)
	@echo "COMPILING SO_LONG..."
	$(CCF) -o $(NAME) $(OBJ) $(FT_PRINTF_LIB) $(MLX_LIB) $(INC) -lX11 -lXext
	@echo "./so_long created"

clean:
	@echo "Deleting Obj file in $(MLX_PATH)..."
	@make clean -sC $(MLX_PATH)
	@echo "Done"
	@echo "Deleting Obj file in $(FT_PRINTF_PATH)..."
	@make clean -sC $(FT_PRINTF_PATH)
	@echo "Done"
	@echo "Deleting So_long object..."
	@rm -f $(OBJ)
	@rm -rf $(NAME)
	@echo "Done"

fclean: clean
	@echo "Deleting so_long executable..."
	@rm -rf $(NAME)
	@rm -rf $(FT_PRINTF_PATH)$(FT_PRINTF_FILE)
	@echo "Done"

re: fclean all

.PHONY: all clean fclean re
