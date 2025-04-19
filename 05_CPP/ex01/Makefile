# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanni <asanni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 14:14:46 by asanni            #+#    #+#              #
#    Updated: 2025/04/13 19:18:25 by asanni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02
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
