# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:38:05 by hharrold          #+#    #+#              #
#    Updated: 2019/03/17 19:42:13 by hstiv            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = src/ft_printf.c src/main.c src/ft_type_s.c src/ft_type_d.c src/ft_parsing.c \
	  src/ft_prn_lst.c src/ft_pars_flag.c src/dtype_f/ft_type_f.c src/dtype_f/ft_ftoa.c \
	  src/dtype_f/ft_creat_flst.c src/ft_point_flags.c $(LFT)

HEAD = includes/

LFT = libft/libft.a

OBJ = ~/ft_printf/obj/*.o

#FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@mkdir obj
		@make -C libft re && gcc -o $(NAME) $(SRC) -I $(HEAD)
		@mv *.o ~/ft_printf/obj/
		@echo COMPILED!
clean:
		@rm -rf obj/*.o $(OBJ)
		@make -C libft fclean

fclean: clean
		@rm -rf $(NAME) obj

re: fclean all
