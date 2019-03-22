# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 10:39:56 by hharrold          #+#    #+#              #
#    Updated: 2018/11/22 16:05:31 by hharrold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

HEAD = ./

OBG = *.o

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -I $(HEAD) -c $(SRC)
	@ar r $(NAME) $(OBG)

clean:
	@rm -f $(OBG)

fclean: clean
	@rm -f $(NAME)

re: fclean all
