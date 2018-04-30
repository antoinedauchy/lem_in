/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:37:39 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 18:55:18 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_viewer.h"

int			loop_hook(void *ptr)
{
	t_mlx	mlx;
	t_data	*data;

	data = (t_data*)(ptr);
	mlx = data->mlx;
	update_pos_ants(data);
	fill_image(data->mlx.img, 0x606060);
	print_ways(data->antfarm, data->mlx.img, data->print);
	print_rooms(data);
	print_ants(data);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return (0);
}
