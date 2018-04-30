/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:38:25 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/23 23:35:41 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_viewer.h"

int			key_hook(int keycode, void *ptr)
{
	t_data	*data;

	data = (t_data*)ptr;
	if (keycode == ECHAP)
	{
		free_antfarm(data->antfarm);
		ft_free_2d_tab((void**)data->input, 1);
		ft_free_2d_tab((void**)data->moves, 0);
		exit(0);
	}
	if (keycode == UP)
		data->speed += 1;
	else if (keycode == DOWN && data->speed > 1)
		data->speed -= 1;
	return (0);
}
