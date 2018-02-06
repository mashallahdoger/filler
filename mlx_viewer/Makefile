# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 18:49:22 by adauchy           #+#    #+#              #
#    Updated: 2018/01/11 19:05:22 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc

RM		=		rm -f

NAME	=		mlx_viewer

CFLAGS	=		-Wextra -Wall -Werror

LIB		=		-lmlx -framework OpenGL -framework AppKit -O3

SRCS	=		mlx_viewer.c		\
				init_mlx.c			\
				loop_hook.c			\
				key_hook.c			\
				put_pxl_img.c		\
				print_square.c		\
				get_buffer.c		\
				get_nbr.c			\
				ft_strstr.c			\
				ft_strcat.c			\

OBJS	=		$(SRCS:.c=.o)

HEADER	=		mlx_viewer.h

all		:		$(NAME)

$(NAME)	:		$(OBJS)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIB)

%.o		:		%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean	:
				$(RM) $(OBJS)

fclean	:		clean
				$(RM) $(NAME)

re		:		fclean all

.PHONY	:		all clean fclean re
