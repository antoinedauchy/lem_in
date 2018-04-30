/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:09:20 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 19:07:39 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_viewer.h"

int		init_ants_viewer(t_data *data)
{
	int		count;
	t_ant	*ants;

	if (!(data->antfarm.ants = (t_ant*)malloc(data->antfarm.nb_ants *
					sizeof(t_ant))))
		return (-1);
	count = 0;
	ants = data->antfarm.ants;
	while (count < data->antfarm.nb_ants)
	{
		ants[count].action = IN_ROOM;
		ants[count].room = data->antfarm.start;
		ants[count].pos_x = (ants[count].room->pos_x -
				data->print.min_x) * data->print.size_room +
				data->print.size_room / 2;
		ants[count].pos_y = (ants[count].room->pos_y -
				data->print.min_y) * data->print.size_room +
				data->print.size_room / 2;
		ants[count].angle = 0;
		count += 1;
	}
	return (0);
}
