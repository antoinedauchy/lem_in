/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:45:39 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 18:34:33 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_viewer.h"

int			get_width_antfarm(t_data *data, t_print *p)
{
	t_list	*tmp;

	p->min_x = 100;
	p->min_y = 100;
	p->max_x = 0;
	p->max_y = 0;
	tmp = data->antfarm.rooms;
	while (tmp)
	{
		if (((t_room*)tmp->content)->pos_x < p->min_x)
			p->min_x = ((t_room*)tmp->content)->pos_x;
		if (((t_room*)tmp->content)->pos_x > p->max_x)
			p->max_x = ((t_room*)tmp->content)->pos_x;
		if (((t_room*)tmp->content)->pos_y < p->min_y)
			p->min_y = ((t_room*)tmp->content)->pos_y;
		if (((t_room*)tmp->content)->pos_y > p->max_y)
			p->max_y = ((t_room*)tmp->content)->pos_y;
		tmp = tmp->next;
	}
	if (p->max_x - p->min_x > p->max_y - p->min_y)
		return (p->max_x - p->min_x);
	return (p->max_y - p->min_y);
}

void		modify_coord(t_list *list, int *width)
{
	t_room	*room;

	if (*width <= 100)
		return ;
	while (list)
	{
		room = (t_room*)list->content;
		room->pos_x = room->pos_x * 100 / *width;
		room->pos_y = room->pos_y * 100 / *width;
		list = list->next;
	}
}

void		init_size(t_data *data)
{
	int		width;
	double	zoom;

	width = get_width_antfarm(data, &data->print);
	modify_coord(data->antfarm.rooms, &width);
	width = get_width_antfarm(data, &data->print);
	zoom = (width == 100 ? width : 100.0 / (width + 1));
	data->print.size_room = (double)SIZE_ROOM * zoom;
	data->print.size_way = (double)SIZE_WAY * zoom;
	data->print.height_ant = (double)HEIGHT_ANT * zoom;
	data->print.lenght_ant = (double)LENGHT_ANT * zoom;
}

void		init_print(t_data *data)
{
	t_list	*tmp;
	int		count;
	int		size_list;

	count = 0;
	tmp = data->antfarm.rooms;
	size_list = get_size_list(tmp);
	while (tmp)
	{
		((t_room*)tmp->content)->color =
			get_color(count, START_COLOR, END_COLOR, size_list);
		tmp = tmp->next;
		count += 1;
	}
	data->move = 0;
	data->speed = 1.0;
	init_size(data);
}
