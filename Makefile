NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MFLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
SRC = sources/main.c\
sources/mandelbrot.c\
sources/julia.c\
utils/mlx_utils.c\
utils/fractol_utils.c
OBJS = $(SRC:.c=.o)

ifndef GRADIENT
GRADIENT = 0x2211FF
endif

ifndef MAX_ITER
MAX_ITER = 42
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) mlx
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) $(LIBFT) -o $(NAME)

mlx:
	make -C $(MLX_DIR) all

$(LIBFT):
	make -C $(LIBFT_DIR)

set: CFLAGS += -DGRADIENT=$(GRADIENT) -DMAX_ITER=$(MAX_ITER)
set: re

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all