NAME = ft_printf

SRCS = ft_print.c

LFT = libft/libft.a

HEAER = libft/

FL = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):
	make -C libft/ re && gcc -o $(NAME) $(FL) $(SRCS) -I $(HEAER)
	
clean:
	rm -f *.o
	make -C libft/ fclean
	
fclean:clean
	rm -f $(NAME)
	
re: fclean all
