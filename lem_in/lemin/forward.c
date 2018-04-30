/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:09:49 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/23 19:08:08 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*get_fastest_way(t_room *room, int non_taken)
{
	t_list	*tmp;
	t_room	*fastest;

	tmp = room->links;
	fastest = NULL;
	while (tmp)
	{
		if (non_taken)
		{
			if (!fastest && !((t_room*)tmp->content)->nb_ants)
				fastest = (t_room*)tmp->content;
			else if (fastest && !((t_room*)tmp->content)->nb_ants &&
					fastest->dist > ((t_room*)tmp->content)->dist)
				fastest = (t_room*)tmp->content;
		}
		else
		{
			if (!fastest || ((t_room*)tmp->content)->dist < fastest->dist)
				fastest = (t_room*)tmp->content;
		}
		tmp = tmp->next;
	}
	return (fastest);
}

void		travel_it(t_room *dest, t_room *src, t_ant *ants, int ant)
{
	dest->nb_ants += 1;
	src->nb_ants -= 1;
	ants[ant].room = dest;
	ft_printf("L%d-%s", ant + 1, dest->name);
}

void		forward_ant(t_antfarm *antfarm, int count, int *first_print)
{
	t_room	*fastest_way;
	t_room	*fastest_free_way;

	fastest_way = get_fastest_way(antfarm->ants[count].room, 0);
	if (!fastest_way->nb_ants || fastest_way == antfarm->end)
	{
		if (!*first_print)
			ft_printf(" ");
		travel_it(fastest_way, antfarm->ants[count].room,
		antfarm->ants, count);
		*first_print = 0;
	}
	else if ((fastest_free_way = get_fastest_way(antfarm->ants[count].room, 1)))
	{
		if (fastest_free_way->dist - antfarm->ants[count].room->nb_ants <=
				fastest_way->dist)
		{
			if (!*first_print)
				ft_printf(" ");
			travel_it(fastest_free_way, antfarm->ants[count].room,
						antfarm->ants, count);
			*first_print = 0;
		}
	}
}

int			forward(t_antfarm *antfarm)
{
	int		count;
	int		first_print;

	first_print = 1;
	if (antfarm->end->nb_ants == antfarm->nb_ants)
		return (0);
	count = 0;
	while (count < antfarm->nb_ants)
	{
		if (antfarm->ants[count].room != antfarm->end)
			forward_ant(antfarm, count, &first_print);
		count += 1;
	}
	return (1);
}
