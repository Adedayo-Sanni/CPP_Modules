# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanni <asanni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:14:46 by asanni            #+#    #+#              #
#    Updated: 2025/03/23 16:27:05 by asanni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00
CFLAGS = -Wall -Werror -Wextra
COMPILE = c++ -std=c++98

CPP = $(wildcard *.cpp)
OBJ = $(CPP:.cpp=.o)


all: $(NAME)


$(NAME): $(OBJ)
	@$(COMPILE) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
