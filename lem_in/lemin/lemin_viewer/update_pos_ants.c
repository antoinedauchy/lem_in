/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:07:47 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 19:49:11 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_viewer.h"

void		get_move_error(int ant, t_room *dest, t_data *data)
{
	t_list	*tmp;

	tmp = NULL;
	if (ant >= 0 && ant < data->antfarm.nb_ants)
		tmp = data->antfarm.ants[ant].room->links;
	while (tmp && ((t_room*)tmp->content) != dest)
		tmp = tmp->next;
	if (!tmp || (((t_room*)tmp->content) != data->antfarm.end &&
				((t_room*)tmp->content)->nb_ants))
		exit(ft_put_err("Impossible move"));
}

void		place_ant(int ant, t_room *dest, t_data *data)
{
	t_ant	*ants;
	int		src_x;
	int		src_y;
	int		dest_x;
	int		dest_y;

	get_move_error(ant, dest, data);
	ants = data->antfarm.ants;
	ants[ant].room->nb_ants -= 1;
	src_x = (ants[ant].room->pos_x - data->print.min_x) *
		data->print.size_room + data->print.size_room / 2;
	src_y = (ants[ant].room->pos_y - data->print.min_y) *
		data->print.size_room + data->print.size_room / 2;
	dest_x = (dest->pos_x - data->print.min_x) * data->print.size_room +
		data->print.size_room;
	dest_y = (dest->pos_y - data->print.min_y) * data->print.size_room +
		data->print.size_room;
	ants[ant].action = IN_WAY;
	ants[ant].angle = 90 - get_angle(dest_x - src_x, dest_y - src_y);
	ants[ant].speed_x = (dest->pos_x - ants[ant].room->pos_x);
	ants[ant].speed_y = (dest->pos_y - ants[ant].room->pos_y);
	ants[ant].room = dest;
	dest->nb_ants += 1;
}

void		place_ants_on_way(t_data *data)
{
	int		n;
	int		m;
	char	*str;
	t_list	*tmp;

	str = data->moves[data->move];
	n = 0;
	while (42)
	{
		while (n && str[n] && str[n] != ' ')
			n += 1;
		if (!str[n] || !str[n + 1] || !str[n + 2] || !(n += 1))
			return ;
		if (n - 1)
			n += 1;
		m = n;
		while (str[m] && str[m] != '-')
			m += 1;
		tmp = data->antfarm.rooms;
		while (ft_strccmp(&str[m + 1], ((t_room*)tmp->content)->name, ' '))
			tmp = tmp->next;
		if (!tmp)
			exit(ft_put_err("Impossible move"));
		place_ant(ft_atoi(&str[n]) - 1, (t_room*)tmp->content, data);
	}
}

void		get_arrived_ant(t_ant *ant, t_data *data)
{
	int		dest_x;
	int		dest_y;

	dest_x = (ant->room->pos_x - data->print.min_x) * data->print.size_room +
		data->print.size_room / 2;
	dest_y = (ant->room->pos_y - data->print.min_y) * data->print.size_room +
		data->print.size_room / 2;
	if (((ant->speed_x >= 0 && ant->pos_x >= dest_x) ||
		(ant->speed_x <= 0 && ant->pos_x <= dest_x)) &&
		((ant->speed_y >= 0 && ant->pos_y >= dest_y) ||
		(ant->speed_y <= 0 && ant->pos_y <= dest_y)))
	{
		ant->pos_x = (ant->room->pos_x - data->print.min_x) *
		data->print.size_room + data->print.size_room / 2;
		ant->pos_y = (ant->room->pos_y - data->print.min_y) *
		data->print.size_room + data->print.size_room / 2;
		ant->action = IN_ROOM;
	}
}

void		update_pos_ants(t_data *data)
{
	int		count;
	t_ant	*ants;
	int		all_ants_in_room;

	ants = data->antfarm.ants;
	count = 0;
	all_ants_in_room = 1;
	while (count < data->antfarm.nb_ants)
	{
		if (ants[count].action == IN_WAY && !(all_ants_in_room = 0))
		{
			ants[count].pos_x += ants[count].speed_x * data->speed;
			ants[count].pos_y += ants[count].speed_y * data->speed;
		}
		get_arrived_ant(&ants[count], data);
		count += 1;
	}
	if (all_ants_in_room)
	{
		if (!data->moves[data->move])
			return ;
		place_ants_on_way(data);
		data->move += 1;
	}
}
