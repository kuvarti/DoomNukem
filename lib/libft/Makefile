# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 11:01:10 by aeryilma          #+#    #+#              #
#    Updated: 2024/03/28 11:44:33 by aeryilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -fPIC
FILES = $(shell find . -name '*.c')
OBJ = $(FILES:%.c=%.o)

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

all: firstecho ${NAME}

firstecho:
	@echo "Compiling Libft..."

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "Libft compiled."

clean:
	@find . -name '*.o' -delete
	@echo "Libft cleaning."

fclean: clean
	@if [ -e $(NAME) ]; then rm $(NAME); fi
	@echo "Libft Deleted."

re: clean all

.PHONY:
	all ofile clean
