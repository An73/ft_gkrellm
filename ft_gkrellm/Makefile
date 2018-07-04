# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazarev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 13:28:43 by alazarev          #+#    #+#              #
#    Updated: 2018/06/30 12:46:25 by alazarev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC = main.cpp CPU.cpp DateTime.cpp User.cpp OS.cpp Network.cpp RAM.cpp Ncurs.cpp Ncurs_static.cpp AnimalModule.cpp
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
FLAG = -Wall -Wextra -Werror
CC = clang++

all: $(NAME)
   
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lncurses

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	$(CC) -c $< -o $@ $(FLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
