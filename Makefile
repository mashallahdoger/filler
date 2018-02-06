# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 18:44:15 by adauchy           #+#    #+#              #
#    Updated: 2018/01/11 19:05:24 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc

RM		=		rm -f

NAME	=		adauchy.filler

CFLAGS	=		-Wextra -Wall -Werror

SRCS	=		main.c					\
				get_nbr.c				\
				ft_strstr.c				\
				get_best_position.c		\
				get_input.c				\
				input_functions.c		\
				ft_strcmp.c				\
				ft_put_err.c			\
				is_better_place.c		\
				get_dist.c				\
				ft_sqrt.c				\
				create_zone.c			\

OBJS	=		$(SRCS:.c=.o)

HEADER 	= 		filler.h

all		:		$(NAME)

$(NAME)	:		$(OBJS)
				cd ft_printf/; make
				cd mlx_viewer/; make
				$(CC) -o $(NAME) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a

%.o 	: 		%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean	:
				$(RM) $(OBJS)
				cd ft_printf/; make clean;
				cd mlx_viewer/; make clean;

fclean	:		clean
				$(RM) $(NAME)
				cd ft_printf/; make fclean;
				cd mlx_viewer/; make fclean;

re		:		fclean all

.PHONY	:		all clean fclean re
