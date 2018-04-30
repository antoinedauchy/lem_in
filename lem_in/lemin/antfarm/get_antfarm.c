/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_antfarm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:13:49 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 18:19:51 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "antfarm.h"

int			check_start_end_link(t_room *room, t_room *end)
{
	t_list	*tmp;
	t_room	*link;

	room->var = 1;
	tmp = room->links;
	while (tmp)
	{
		link = (t_room*)tmp->content;
		if (link == end && !(room->var = 0))
			return (1);
		if (!link->var && check_start_end_link(link, end) && !(room->var = 0))
			return (1);
		tmp = tmp->next;
	}
	room->var = 0;
	return (0);
}

int			check_antfarm(t_antfarm *antfarm)
{
	if (!check_start_end_link(antfarm->start, antfarm->end))
		return (ft_put_err("START and END rooms not linked"));
	antfarm->start->nb_ants = antfarm->nb_ants;
	return (0);
}

int			get_antfarm(t_antfarm *antfarm, char **input)
{
	int		n;
	int		ret;

	n = 0;
	if ((antfarm->nb_ants = get_nb_ants(input[n++])) == -1)
		return (ft_put_err("Missing ants number"));
	antfarm->start = NULL;
	antfarm->end = NULL;
	antfarm->rooms = NULL;
	while ((ret = get_room(input, antfarm, &n, ANY)))
		if (ret == -1 && ft_printf("%d\n", n))
			return (-1);
	if (!antfarm->start || !antfarm->end)
		return (ft_put_err("missing ##start or ##end room"));
	while ((ret = get_links(input, antfarm, &n)))
		if (ret == -1 && ft_printf("%d\n", n))
			return (-1);
	if (check_antfarm(antfarm) == -1)
		return (-1);
	return (0);
}
