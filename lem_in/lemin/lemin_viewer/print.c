/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:21:54 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 18:50:41 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_viewer.h"

void		print_double_way(t_coord a, t_coord b, t_print p, t_img img)
{
	print_way(a, b, p.size_way, img);
	a.x += 1;
	b.x += 1;
	print_way(a, b, p.size_way, img);
}

void		print_ways(t_antfarm antfarm, t_img img, t_print p)
{
	t_list	*tmp;
	t_list	*link;
	t_coord	a;
	t_coord	b;
	t_room	*room;

	tmp = antfarm.rooms;
	while (tmp)
	{
		room = ((t_room*)tmp->content);
		a.x = (room->pos_x - p.min_x) * p.size_room + p.size_room / 2;
		a.y = (room->pos_y - p.min_y) * p.size_room + p.size_room / 2;
		a.color = room->color;
		link = room->links;
		while (link)
		{
			room = ((t_room*)link->content);
			b.x = (room->pos_x - p.min_x) * p.size_room + p.size_room / 2;
			b.y = (room->pos_y - p.min_y) * p.size_room + p.size_room / 2;
			b.color = room->color;
			print_double_way(a, b, p, img);
			link = link->next;
		}
		tmp = tmp->next;
	}
}

void		print_rooms(t_data *data)
{
	t_list	*tmp;
	t_coord	pos;
	t_coord	size;
	t_room	*room;

	tmp = data->antfarm.rooms;
	pos.color = 0x00FF00;
	while (tmp)
	{
		room = ((t_room*)tmp->content);
		pos.x = (room->pos_x - data->print.min_x) * data->print.size_room;
		pos.y = (room->pos_y - data->print.min_y) * data->print.size_room;
		size.color = room->color;
		size.x = data->print.size_room;
		size.y = data->print.size_room;
		print_trans_color_img(data->mlx.img, data->imgs.room, pos, size);
		tmp = tmp->next;
	}
}

void		print_ants(t_data *data)
{
	t_coord	pos;
	t_coord	size;
	int		count;

	pos.color = 0x00FF00;
	size.x = data->print.lenght_ant;
	size.y = data->print.height_ant;
	count = 0;
	while (count < data->antfarm.nb_ants)
	{
		pos.x = data->antfarm.ants[count].pos_x - data->print.lenght_ant / 2;
		pos.y = data->antfarm.ants[count].pos_y - data->print.height_ant / 2;
		size.color = data->antfarm.ants[count].angle;
		print_trans_img(data->mlx.img, data->imgs.ant, pos, size);
		count += 1;
	}
}
