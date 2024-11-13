NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	make -C $(PRINTF_DIR)
	cp $(PRINTF_DIR)/libftprintf.a libft.a
	rm $(PRINTF_DIR)/libftprintf.a

clean:
	rm -rf $(OBJS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	make -C $(PRINTF_DIR) fclean

re: fclean all
