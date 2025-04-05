# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanni <asanni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:14:46 by asanni            #+#    #+#              #
#    Updated: 2025/04/05 19:52:30 by asanni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00
CFLAGS = -Wall -Werror -Wextra
COMPILE = c++ -std=c++98

CPP = $(wildcard *.cpp)
OBJ = $(CPP:.cpp=.o)


all: $(NAME)

%.o : %.cpp 
	$(COMPILE) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(COMPILE) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
