# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 20:48:53 by ctelma            #+#    #+#              #
#    Updated: 2019/09/12 20:54:21 by ctelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = functions.a

CC = gcc

RM = rm -f

LDFLAGS = -L.

LDLIBS = -lft

HDDIRS = -I .

MAIN = main.c sudoku.c

EXE = sudoku

SRC = ft_putchar.c ft_putstr.c ft_strlen.c

OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) compile
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $< -c -o  $@

compile:
    $(CC) -o $(EXE) $(MAIN) $(NAME)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
