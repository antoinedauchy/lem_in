/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_viewer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:41:33 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/23 23:37:50 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_VIEWER_H
# define LEMIN_VIEWER_H

# include "../../mnlbx/mnlbx.h"
# include "../lemin.h"

# define START_COLOR	0x6B6313
# define END_COLOR		0x561515

# define SIZE_ROOM		10
# define SIZE_WAY		4
# define LENGHT_ANT		6
# define HEIGHT_ANT		LENGHT_ANT * 463 / 325

# define IN_WAY		1
# define IN_ROOM	2

typedef struct		s_print
{
	int				size_room;
	int				size_way;
	int				lenght_ant;
	int				height_ant;
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
}					t_print;

typedef struct		s_imgs
{
	t_img			ant;
	t_img			room;
}					t_imgs;

typedef struct		s_data
{
	t_mlx			mlx;
	t_imgs			imgs;
	t_antfarm		antfarm;
	char			**input;
	char			**moves;
	int				move;
	int				n;
	int				speed;
	t_print			print;
}					t_data;

int					ft_printf(const char *restrict format, ...);
char				**get_moves(char **input);
void				init_print(t_data *data);
void				update_pos_ants(t_data *data);
void				print_ways(t_antfarm antfarm, t_img img, t_print p);
void				print_rooms(t_data *data);
void				print_ants(t_data *data);
int					init_ants_viewer(t_data *data);

#endif
