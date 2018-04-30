# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 19:56:28 by adauchy           #+#    #+#              #
#    Updated: 2018/01/24 19:56:29 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc

RM			=		rm -f

NAME		=		lemin_viewer

CFLAGS		=		-Wextra -Wall -Werror

LIBFT		=		../../libft/libft.a

MLX			=		-lmlx -framework OpenGL -framework AppKit -O3

MNLBX		=		../../mnlbx/mnlbx.a

SRCS		=		main.c						\
					../antfarm/check_nb.c		\
					../antfarm/get_antfarm.c	\
					../antfarm/get_coord.c		\
					../antfarm/get_links.c		\
					../antfarm/get_nb_ants.c	\
					../antfarm/get_room.c		\
					../antfarm/free_antfarm.c	\
					init_ants.c					\
					get_moves.c					\
					key_hook.c					\
					loop_hook.c					\
					init.c						\
					update_pos_ants.c			\
					print.c						\

OBJS		=		$(SRCS:.c=.o)

HEADER 		= 		lemin_viewer.h

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MNLBX)

%.o 		: 		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all

.PHONY		:		all clean fclean re
