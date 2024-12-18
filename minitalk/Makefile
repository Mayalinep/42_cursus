# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 13:46:11 by mpelage           #+#    #+#              #
#    Updated: 2024/12/18 14:32:52 by mpelage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = server.c minitalk.utils.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
NAME_SERVER = server
NAME_CLIENT = client

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT) : $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

clean :
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean : clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re : fclean all

.PHONY : all clean fclean re