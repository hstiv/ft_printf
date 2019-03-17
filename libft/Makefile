# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 10:39:56 by hharrold          #+#    #+#              #
#    Updated: 2019/03/17 00:56:38 by hstiv            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

OBG = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I ../includes
	ar r $@ $(OBG)
	ranlib $@

clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME)

re: fclean all
