/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nodes_distance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 11:25:19 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/22 23:59:39 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			get_min_distance(t_room *room, t_room *start,
					t_room *end, int *dist)
{
	t_list		*tmp;
	t_room		*link;

	if (room == end && start->dist > *dist)
	{
		start->dist = *dist;
		return ;
	}
	*dist += 1;
	room->var = 1;
	tmp = room->links;
	while (tmp)
	{
		link = (t_room*)tmp->content;
		if (!link->var)
			get_min_distance(link, start, end, dist);
		tmp = tmp->next;
	}
	room->var = 0;
	*dist -= 1;
}

void			write_nodes_distance(t_antfarm *antfarm)
{
	t_list		*tmp;
	int			dist;
	int			dist_max;

	tmp = antfarm->rooms;
	dist_max = get_size_list(antfarm->rooms);
	while (tmp)
	{
		dist = 0;
		((t_room*)tmp->content)->dist = dist_max;
		get_min_distance((t_room*)tmp->content, (t_room*)tmp->content,
				antfarm->end, &dist);
		tmp = tmp->next;
	}
}
