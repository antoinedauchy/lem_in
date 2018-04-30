/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:21:46 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 18:26:57 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "antfarm.h"

int			get_home_room(char **input, t_antfarm *antfarm, int *n)
{
	if (!ft_strcmp("##start", input[*n]))
	{
		if (antfarm->start)
			return (ft_put_err("To many ##start room in file"));
		*n += 1;
		get_room(input, antfarm, n, START);
		return (1);
	}
	if (!ft_strcmp("##end", input[*n]))
	{
		if (antfarm->end)
			return (ft_put_err("To many ##end roome in file"));
		*n += 1;
		get_room(input, antfarm, n, END);
		return (1);
	}
	return (0);
}

int			get_data_room(char **input, int *n, t_room *room)
{
	int		m;

	m = 0;
	room->nb_ants = 0;
	room->var = 0;
	room->dist = 0;
	room->links = NULL;
	if (input[*n][m] == 'L')
		return (ft_put_err("room name can't begin by 'L'"));
	if (!ft_strclen(input[*n], ' '))
		return (ft_put_err("Error in room format"));
	if (!(room->name = ft_strcdup(input[*n], ' ')))
		return (-1);
	while (input[*n][m] && input[*n][m] != ' ')
		m += 1;
	m += 1;
	if (!get_coord(&room->pos_x, &input[*n][m]) ||
			check_nb(input[*n], &m, ' ') == -1)
		return (-1);
	m += 1;
	if (get_coord(&room->pos_y, &input[*n][m]) == -1 ||
			check_nb(input[*n], &m, '\0') == -1)
		return (-1);
	return (1);
}

int			check_line(char **input, int *n)
{
	int		m;

	if (!input[*n])
		return (0);
	return (check_link(input[*n], &m, n, 0));
}

int			get_room(char **input, t_antfarm *antfarm, int *n, int status)
{
	t_room		*room;
	int			ret;
	int			m;

	m = 0;
	if (!input[*n])
		return (0);
	if ((ret = get_home_room(input, antfarm, n)))
		return (ret);
	if (!check_line(input, n))
		return (0);
	if ((!ft_strncmp(input[*n], "#", 1) ||
		!ft_strncmp(input[*n], "##", 2)) && (*n += 1))
		return (1);
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (ft_put_err("malloc failed"));
	if ((ret = get_data_room(input, n, room)) <= 0)
		return (ret);
	ft_list_push_back(&antfarm->rooms, room);
	if (status == START)
		antfarm->start = room;
	else if (status == END)
		antfarm->end = room;
	*n += 1;
	return (1);
}
