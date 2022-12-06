# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:11:50 by hrobin            #+#    #+#              #
#    Updated: 2022/12/06 16:33:54 by hrobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

FLAGS		= -Wall -Wextra -Werror

FT_DIR		= Utils/

SRCS 		=	${FT_DIR}ft_hexa.c \
				${FT_DIR}ft_percent.c \
				${FT_DIR}ft_putchar.c \
				${FT_DIR}ft_putnbr.c \
				${FT_DIR}ft_putstr.c \
				ft_printf.c \

OBJS 		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

all: ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all clean fclean
