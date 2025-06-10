# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 19:41:47 by ralves-e          #+#    #+#              #
#    Updated: 2025/05/10 18:11:09 by ralves-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_phonebook
SRC = main.cpp MyPhoneBook.cpp PhoneBook.cpp Contact.cpp
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
