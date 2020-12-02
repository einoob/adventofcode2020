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

NAME1 = first_part

NAME2 = second_part

SRC1 = ./reportrepair.c

SRC2 = ./second_part.c

LIB = ../libftprintf/libftprintf.a

FLAGS = -Wall -Werror -Wextra

all: first second

first: $(NAME1)

second: $(NAME2)


$(NAME1):
	@ make -C ../libftprintf/ 
	@ gcc $(FLAGS) -o $(NAME1) $(SRC1) $(LIB)
	@ echo "Compiled p1"

$(NAME2):
	@ make -C ../libftprintf/ 
	@ gcc $(FLAGS) -o $(NAME2) $(SRC2) $(LIB)
	@ echo "Compiled p2"

clean:
	@ make -C ../libftprintf/ clean
	@ /bin/rm -f *.o

fclean: clean
	@ make -C ../libftprintf/ fclean
	@ /bin/rm -f $(NAME1) $(NAME2)
	@ echo "Executable and libraries removed"

re : fclean all
