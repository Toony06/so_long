# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 09:33:14 by toroman           #+#    #+#              #
#    Updated: 2025/01/07 10:18:27 by toroman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parsing.c parsing2.c floodfil.c mlx.C
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFT = ./utils
INCLUDES = -I/usr/include -Imlx -Iincludes
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./utils/
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./utils/utils.a ${MLX_FLAGS}

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	${MAKE} clean -C ./utils/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./utils/utils.a

re: fclean all

.PHONY: all clean fclean re
