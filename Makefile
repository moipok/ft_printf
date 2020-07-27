# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/13 01:54:12 by fbarbera          #+#    #+#              #
#    Updated: 2020/07/18 22:00:55 by fbarbera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_atoi.c ft_strchr.c \
		hex16.c ft_ifc.c \
		ft_ifdi.c ft_ifp.c \
		ft_ifs.c ft_ifu.c \
		ft_ifx.c putchars.c \
		ft_substr.c ft_calloc.c \
		ft_bzero.c ft_identy.c

SRCO = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(SRCO) ft_printf.h
	gcc $(FLAGS) -I ./ $(SRCS)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $< -o $@

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) clean fclean re

