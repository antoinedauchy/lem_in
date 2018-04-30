/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antfarm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 00:58:42 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/23 20:09:45 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTFARM_H
# define ANTFARM_H

# include "../../libft/libft.h"

# define START		1
# define END		2
# define ANY		3

# define IN_WAY		1
# define IN_ROOM	2

typedef struct		s_room
{
	int				pos_x;
	int				pos_y;
	char			*name;
	int				nb_ants;
	int				color;
	int				var;
	int				dist;
	t_list			*links;
}					t_room;

typedef struct		s_ant
{
	int				action;
	t_room			*room;
	int				pos_x;
	int				pos_y;
	int				angle;
	int				speed_x;
	int				speed_y;
}					t_ant;

typedef struct		s_antfarm
{
	int				nb_ants;
	t_ant			*ants;
	t_room			*start;
	t_room			*end;
	t_list			*rooms;
}					t_antfarm;

int					get_nb_ants(char *str);
int					get_room(char **input, t_antfarm *antfarm, int *n,
						int status);
int					get_links(char **input, t_antfarm *antfarm, int *n);
int					get_coord(int *nb, char *str);
int					check_nb(char *str, int *n, char car);
int					check_link(char *str, int *second_room, int *pos,
						int put_err);
int					get_antfarm(t_antfarm *antfarm, char **input);
void				free_antfarm(t_antfarm antfarm);

#endif
