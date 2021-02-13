# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburton <rburton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 11:32:38 by rburton           #+#    #+#              #
#    Updated: 2021/02/13 21:29:44 by rburton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	ft_printf.c \
				ft_printf2.c \
				ft_printf_main.c \


OBJS		= ${SRC:.c=.o}

NAME		= a.out

GCC			= gcc

CFLAGS		= -g -Wall -Wextra -Werror

RM			= rm -f

FT_H		= ft_printf.h

all:	${NAME}

#сопоставление *.c и *.o файлов
.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${GCC} ${CFLAGS} -o ${NAME} ${OBJS}


#main:
#		${GCC} ${CFLAGS} ${LIB} ft_mnrt_main.c

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} ${LIB}

re:		fclean all
