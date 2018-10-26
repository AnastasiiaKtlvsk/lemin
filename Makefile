# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotilie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/01 19:50:05 by akotilie          #+#    #+#              #
#    Updated: 2018/08/12 12:08:45 by akotilie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

LEMIN =  start.c parse.c process.c print.c free.c

LIBFT = libft/libft.a

COMPILED = $(LEMIN:.c=.o)

all: $(NAME)

$(NAME): $(COMPILED) $(LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(COMPILED) $(LIBFT)

$(LIBFT):	liball

liball:
	@make -C ./libft
	
clean:
	@rm -f *.o
	@ make clean -C libft/

fclean: clean
	@ make fclean -C libft/
	@ rm -rf $(NAME)

re: fclean all
