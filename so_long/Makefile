# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzona <hzona@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 16:12:07 by hzona             #+#    #+#              #
#    Updated: 2021/10/29 22:56:34 by hzona            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c sprite.c	update.c check_map.c read_file.c str_utils.c window.c error.c str_utils2.c windows2.c check.c ft_itoa.c

SRCS_DIR = src/

OBJS = ${addprefix ${SRCS_DIR}, ${SRC:.c=.o}}

HEADER = src/so_long.h

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

REMOVE = rm -f

.PHONY: all clean fclean re bonus

%.o:%.c		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC}	${OBJS} src/libmlx.a -framework OpenGL -framework AppKit -o ${NAME}
			@echo "so_long compiled successfully!"

bonus:		${NAME}

all:		${NAME}

fclean:		
			@${RM} ${OBJS} ${NAME}
			@echo "fclean successfully!"

clean:		
			@${RM} ${OBJS}
			@echo "fclean successfully!"

re: fclean all