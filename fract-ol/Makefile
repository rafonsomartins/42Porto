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

$(NAME): $(LIBFT) mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) $(LIBFT) -o $(NAME)

mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning minilibx-linux..."; \
		git clone git@github.com:42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	make -C $(MLX_DIR) all

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)/.git" ]; then \
		echo "Cloning only 'libft' folder into $(LIBFT_DIR)..."; \
		mkdir -p $(LIBFT_DIR); \
		cd $(LIBFT_DIR) && \
		git init && \
		git remote add origin git@github.com:rafonsomartins/42Porto; \
		git config core.sparseCheckout true; \
		echo "libft/*" >> .git/info/sparse-checkout; \
		git pull origin main; \
	else \
		echo "$(LIBFT_DIR) already initialized and cloned."; \
	fi
	mv libft/libft libft_1
	rm -rf libft
	mv libft_1 libft
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