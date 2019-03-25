# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:38:05 by hharrold          #+#    #+#              #
#    Updated: 2019/03/24 01:18:38 by hstiv            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_printf.c src/ft_type_s.c src/ft_type_d.c \
	  src/ft_prn_lst.c src/ft_pars_flag.c src/dtype_f/ft_type_f.c src/dtype_f/pf_ftoa.c \
	  src/dtype_f/facc.c src/ft_point_flags_f_d_i.c src/ft_putnbr_prntf.c \
	  src/dtype_f/rounding.c src/bonus/ft_type_b_e.c src/bonus/ft_type_g.c \
	  src/ft_numlen_for_prf.c

HEAD = ./includes/

WWW = -Wall -Wextra -Werror

OBG = ./obj/*.o

LFT = libft

all: $(NAME)

$(NAME):
		@mkdir obj
		@gcc $(WWW) -I $(HEAD) -c $(SRC)
		@mv *.o obj/ 
		@make -C $(LFT) re
		@cp libft/libft.a ./$(NAME)
		@ar rc -g $(NAME) $(OBG)
		@renlib $(NAME)
#		@echo COMPILED!

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
