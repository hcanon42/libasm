# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcanon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 00:56:42 by hcanon            #+#    #+#              #
#    Updated: 2020/07/09 10:25:11 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	= ${ASMSRCS:.s=.o}
ASMFLAGS	= -f elf64
CC	= clang
CFLAGS	= -Wall -Werror -Wextra
NAME	= libasm.a
MAIN	= main.c
ASMSRCS	= ft_strlen.s \
	  ft_strcpy.s \
	  ft_strcmp.s \
	  ft_write.s \
	  ft_read.s \
	  ft_strdup.s \

.s.o :
	nasm ${ASMFLAGS} $< -o $@

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

test:
			${CC} ${CFLAGS} ${MAIN} ${NAME} -o asm_test

all:		$(NAME)

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}
			rm -f asm_test

re:			fclean ${NAME}

.PHONY:		all clean fclean re test
