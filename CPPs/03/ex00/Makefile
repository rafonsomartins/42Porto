# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 17:09:33 by ralves-e          #+#    #+#              #
#    Updated: 2025/06/10 17:16:00 by ralves-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed_points
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
