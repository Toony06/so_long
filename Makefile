# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tony <tony@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 09:33:14 by toroman           #+#    #+#              #
#    Updated: 2025/01/02 19:32:42 by tony             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parsing.c parsing2.c floodfil.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./utils
INCLUDES = -I/usr/include -Imlx -Iincludes

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
