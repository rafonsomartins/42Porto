NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -g -pthread
FLAGS += -fsanitize=thread # -fsanitize=address
SRC = main.c\
      sources/check_str.c\
      sources/parser.c\
	  sources/init_var.c\
      sources/run_sim.c\
	  sources/check_philos.c\
	  sources/free_stuff.c\
      sources/philos/routine.c\
	  sources/philos/init_var_philo.c\
	  sources/philos/actions/eat.c\
	  sources/philos/actions/sleep.c\
	  sources/philos/actions/think.c\
      utils/ft_sleep.c\
	  utils/exit_function.c\
	  utils/atoi.c\
	  utils/ft_isdigit.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
