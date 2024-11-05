# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanni <asanni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 16:20:40 by asanni            #+#    #+#              #
#    Updated: 2024/11/05 19:56:45 by asanni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phone_book
CFLAGS = -Wall -Werror -Wextra
COMPILE = c++ -std=c++98


CPP = $(wildcard ./sources/*.cpp)
HPP = $(wildcard ./include/*.hpp)

all:
	$(COMPILE) $(CPP) $(CFLAGS) -o $(NAME)

