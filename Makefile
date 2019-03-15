# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:38:05 by hharrold          #+#    #+#              #
#    Updated: 2019/03/14 18:55:39 by hstiv            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = src

HEAD = ./includes/

OBG = ./obj/*.o

LFT = libft

all: $(NAME)

$(NAME):
		@mkdir obj
		@gcc \
		-I $(HEAD) \
		-c $(SRC)/ft_print.c $(SRC)/main.c $(SRC)/ft_type_s.c \
		$(SRC)/ft_type_d.c $(SRC)/ft_parsing.c $(SRC)/ft_prn_lst.c \
		$(SRC)/ft_pars_flag.c
		@mv *.o obj/
		@cd $(LFT) && make && cd -
		@gcc  \
		$(OBG) $(LFT)/libft.a -o $(NAME)
		@echo COMPILED!
	#-Wall -Wextra -Werror #
clean:
		@rm -rf $(OBJ)
		@cd $(LFT) && make fclean && cd -

fclean: clean
		@rm -rf obj/
		@rm -rf ft_printf

re: fclean all
