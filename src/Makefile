# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:38:05 by hharrold          #+#    #+#              #
#    Updated: 2019/03/19 19:21:33 by hstiv            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = src/ft_printf.c src/main.c src/ft_type_s.c src/ft_type_d.c \
	  src/ft_prn_lst.c src/ft_pars_flag.c src/dtype_f/ft_type_f.c src/dtype_f/pf_ftoa.c \
	  src/dtype_f/facc.c src/ft_point_flags.c src/ft_putnbr_prntf.c \
	  src/dtype_f/rounding.c

HEAD = ./includes/

OBG = ./obj/*.o

LFT = libft

all: $(NAME)

$(NAME):
		@mkdir obj
		@gcc \
		-Wall -Wextra -Werror \
		-I $(HEAD) \
		-c $(SRC)
		@mv *.o obj/ 
		@cd $(LFT) && make && cd -
		@gcc -g \
		$(OBG) $(LFT)/libft.a -o $(NAME)
		@echo COMPILED!

clean:
		@rm -rf $(OBJ)
		@cd $(LFT) && make fclean && cd -

fclean: clean
		@rm -rf obj/
		@rm -rf ft_printf

re: fclean all


# NAME = ft_printf

# SRC = src/ft_printf.c src/main.c src/ft_type_s.c src/ft_type_d.c \
# 	  src/ft_prn_lst.c src/ft_pars_flag.c src/dtype_f/ft_type_f.c src/dtype_f/pf_ftoa.c \
# 	  src/dtype_f/facc.c src/ft_point_flags.c src/ft_putnbr_prntf.c \
# 	  src/dtype_f/rounding.c $(LFT)

# HEAD = includes/

# LFT = libft/libft.a

# OBJ = ~/ft_printf/obj/

# #FLAGS = -Wall -Wextra -Werror

# all: $(NAME)

# $(NAME):
# 		@mkdir obj
# 		@make -C libft re && gcc -g -o $(NAME) $(SRC) -I $(HEAD)
# 		@mv *.o $(OBJ)
# 		@echo COMPILED!
# clean:
# 		@rm -rf $(OBJ)/*.o
# 		@make -C libft fclean

# fclean: clean
# 		@rm -rf $(NAME) obj

# re: fclean all
