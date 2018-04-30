/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:51:48 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/22 23:57:08 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "antfarm.h"

int			check_link(char *str, int *second_room, int *pos, int put_err)
{
	int		n;
	int		m;

	n = 0;
	if ((!ft_strncmp(str, "#", 1) || !ft_strncmp(str, "##", 2)))
	{
		if (put_err)
			*pos += 1;
		return (1);
	}
	while (str[n] && str[n] != '-' && str[n] != ' ')
		n += 1;
	if (!n || str[n] != '-')
		if (!put_err || ft_put_err("Error in tube format"))
			return (-1);
	m = 0;
	n += 1;
	while (str[n + m])
		m += 1;
	if (!m)
		if (!put_err || ft_put_err("Error in tube format"))
			return (-1);
	*second_room = n;
	return (0);
}

int			add_link(t_room *room1, t_room *room2)
{
	t_list	*tmp;

	tmp = room1->links;
	while (tmp)
	{
		if (((t_room*)tmp->content) == room2)
			return (ft_put_err("Tube already exist"));
		tmp = tmp->next;
	}
	ft_list_push_back(&room1->links, room2);
	ft_list_push_back(&room2->links, room1);
	return (0);
}

int			get_links(char **input, t_antfarm *antfarm, int *n)
{
	int		ret;
	int		m;
	t_list	*tmp;
	t_room	*room1;

	if (!input[*n])
		return (0);
	tmp = antfarm->rooms;
	if ((ret = check_link(input[*n], &m, n, 1)))
		return (ret);
	while (tmp && ft_strccmp(input[*n], ((t_room*)(tmp->content))->name, '-'))
		tmp = tmp->next;
	if (!tmp)
		return (ft_put_err("Tube not possible"));
	room1 = (t_room*)tmp->content;
	tmp = antfarm->rooms;
	while (tmp && ft_strccmp(&input[*n][m],
				((t_room*)(tmp->content))->name, '\0'))
		tmp = tmp->next;
	if (!tmp)
		return (ft_put_err("Tube not possible"));
	if (add_link(room1, (t_room*)tmp->content) == -1)
		return (-1);
	*n += 1;
	return (1);
}
