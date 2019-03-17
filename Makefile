# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:38:05 by hharrold          #+#    #+#              #
#    Updated: 2019/03/17 01:10:13 by hstiv            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = src/ft_printf.c src/main.c src/ft_type_s.c src/ft_type_d.c src/ft_parsing.c \
	  src/ft_prn_lst.c src/ft_pars_flag.c src/ft_spaces_nol.c src/ft_ftoa.c $(LFT)

HEAD = includes/

LFT = libft/libft.a

OBG = obj/*.o

#FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		mkdir obj
		make -C libft re && gcc -o $(NAME) $(SRC) -I $(HEAD)
		mv *.o obj/
		echo COMPILED!
clean:
		rm -rf *.o $(OBJ)
		make -C libft fclean

fclean: clean
		rm -rf $(NAME) obj

re: fclean all
