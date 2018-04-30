# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/21 05:21:10 by adauchy           #+#    #+#              #
#    Updated: 2018/01/23 22:47:00 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc

RM			=		rm -f

NAME		=		lem-in

CFLAGS		=		-Wextra -Wall -Werror

LIBFT		=		../libft/libft.a

SRCS		=		main.c						\
					antfarm/check_nb.c			\
					antfarm/get_antfarm.c		\
					antfarm/get_coord.c			\
					antfarm/get_links.c			\
					antfarm/get_nb_ants.c		\
					antfarm/get_room.c			\
					antfarm/free_antfarm.c		\
					write_nodes_distance.c		\
					init_ants.c					\
					forward.c					\

OBJS		=		$(SRCS:.c=.o)

HEADER 		= 		lemin.h

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					make -C ../libft
					make -C ../mnlbx
					make -C lemin_viewer
					$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF)

%.o 		: 		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean		:
					$(RM) $(OBJS)
					make clean -C ../libft
					make clean -C ../mnlbx
					make clean -C lemin_viewer

fclean		:		clean
					$(RM) $(NAME)
					make fclean -C ../libft
					make fclean -C ../mnlbx
					make fclean -C lemin_viewer

re			:		fclean all

.PHONY		:		all clean fclean re
