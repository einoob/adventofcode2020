# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 12:18:14 by elindber          #+#    #+#              #
#    Updated: 2020/12/01 12:18:14 by elindber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = repnrep

SRC = ./reportrepair.c

LIB = ../libftprintf/libftprintf.a

FLAGS = #-Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@ make -C ../libftprintf/ 
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)
	@ echo "Compiled"

clean:
	@ make -C ../libftprintf/ clean
	@ /bin/rm -f *.o

fclean: clean
	@ make -C ../libftprintf/ fclean
	@ /bin/rm -f $(NAME)
	@ echo "Executable and libraries removed"

re : fclean all
