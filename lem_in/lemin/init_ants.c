/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:54:51 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/22 20:59:51 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			init_ants(t_antfarm *antfarm)
{
	int		count;

	count = 0;
	if (!(antfarm->ants = (t_ant*)malloc(antfarm->nb_ants * sizeof(t_ant))))
		return (ft_put_err("malloc failed"));
	while (count < antfarm->nb_ants)
	{
		antfarm->ants[count].room = antfarm->start;
		count += 1;
	}
	return (0);
}
