/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_antfarm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:05:53 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/23 22:27:40 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "antfarm.h"

void	free_antfarm(t_antfarm antfarm)
{
	t_room	*room;
	t_list	*next;
	t_list	*next_link;

	free(antfarm.ants);
	while (antfarm.rooms)
	{
		next = antfarm.rooms->next;
		room = (t_room*)antfarm.rooms->content;
		if (room->name)
			free(room->name);
		while (room->links)
		{
			next_link = room->links->next;
			free(room->links);
			room->links = next_link;
		}
		free(room);
		free(antfarm.rooms);
		antfarm.rooms = next;
	}
}
