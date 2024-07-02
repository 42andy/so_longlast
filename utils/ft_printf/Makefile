# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 08:23:03 by astoll            #+#    #+#              #
#    Updated: 2023/11/15 09:18:33 by astoll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c		\
		ft_putchar.c	\
		ft_puthex.c		\
		ft_putnbr.c		\
		ft_putptr.c		\
		ft_putstr.c		\

NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re