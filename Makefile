# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 16:38:05 by hharrold          #+#    #+#              #
#    Updated: 2019/04/03 19:28:05 by hstiv            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_printf.c src/ft_type_s.c src/ft_type_d.c src/dtype_f/inffin.c \
	  src/ft_prn_lst.c src/ft_pars_flag.c src/dtype_f/ft_type_f.c src/dtype_f/pf_ftoa.c \
	  src/dtype_f/facc.c src/ft_point_flags_f_d_i.c src/ft_putnbr_prntf.c src/bonus/ft_flag_r.c\
	  src/dtype_f/rounding.c src/bonus/ft_type_b_e.c src/bonus/ft_type_g.c \
	  src/ft_numlen_for_prf.c src/ft_va_arg_for_d.c src/ft_magic_base.c \
	  src/ft_point_flags_x_o.c src/ft_point_flags_u.c src/bonus/ft_type_e_maker.c

HEAD = ./includes/

WWW = -Wall -Wextra -Werror

OBG = ./obj/*.o

LFT = libft

all: $(NAME)

$(NAME):
		@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
		@mkdir obj
		@gcc $(WWW) \
		-I $(HEAD) \
		-c $(SRC)
		@mv *.o obj/
		@make -C $(LFT) re
		@cp libft/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBG)
		@ranlib $(NAME)
		@echo "(•̀ᴗ•́)و $(NAME) generated!".

clean:
		@rm -rf obj
		@make -C $(LFT) fclean

fclean: clean
		@rm -rf obj	
		@rm -rf $(NAME)
		@echo "(•̀ᴗ•́)و $(NAME) removed!".

re: fclean all
