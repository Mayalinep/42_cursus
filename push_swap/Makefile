# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 15:53:01 by mpelage           #+#    #+#              #
#    Updated: 2025/01/08 16:26:20 by mpelage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -Iincludes


SRCS        = main.c \
              srcs/moves/push.c \
              srcs/moves/reverse_rotate.c \
              srcs/moves/rotate.c \
              srcs/moves/swap.c \
              srcs/sorting/sort_large.c \
              srcs/sorting/sort_small.c \
              srcs/utils/error.c \
              srcs/utils/init_stack.c \
              srcs/utils/stack_utils.c \
              srcs/utils/utils.c \
			  
OBJS        = $(SRCS:.c=.o)

PRINTF_DIR  = ft_printf
PRINTF_LIB  = libftprintf.a


LIBFT_DIR   = $(PRINTF_DIR)/libft
LIBFT_LIB   = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compilation de ft_printf..."
	$(MAKE) -C $(PRINTF_DIR)
	@echo "Compilation de push_swap..."
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) \
		$(PRINTF_DIR)/$(PRINTF_LIB) \
		$(LIBFT_DIR)/$(LIBFT_LIB) \
		-o $(NAME)
	@echo "Terminé : $(NAME) généré."

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
