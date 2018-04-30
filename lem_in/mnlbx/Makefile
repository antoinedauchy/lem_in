# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 18:54:55 by adauchy           #+#    #+#              #
#    Updated: 2018/01/21 05:05:55 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	mnlbx.a

RM			=	rm -f

CC			=	gcc

HEADER 		=	mnlbx.h

LIBFT		=	../libft/libft.a

SRCS 		=	fill_image.c			\
				get_color.c				\
				init_mlx.c				\
				print_line.c			\
				print_polygone.c		\
				print_square.c			\
				print_trans_color_img.c	\
				print_trans_img.c		\
				print_way.c				\
				put_pxl_img.c			\

OBJS 		= 	$(SRCS:.c=.o)

HEADER		=	mnlbx.h

CFLAGS 		= 	-Wall -Werror -Wextra -c

all			:	$(NAME)

$(NAME)		: 	$(OBJS)
				gcc $(CFLAGS) $(SRCS) -I $(HEADER)
				ar rc $(NAME) $(OBJS) $(LIBFT)
				ranlib $(NAME)

%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re
