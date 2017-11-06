#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/05 17:18:43 by vpoltave          #+#    #+#              #
#    Updated: 2017/11/05 19:48:17 by vpoltave         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang++ -Wall -Wextra -Werror
NAME = ft_retro

all:
	$(CC) *cpp -lncurses -o $(NAME)

clean:
	rm -rf $(NAME)
fclean: clean

re: fclean all
