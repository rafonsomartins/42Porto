NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc

# Directories
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

# Libraries
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Source files
SRC = $(wildcard *.c) $(wildcard $(GNL_DIR)/*.c)
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
