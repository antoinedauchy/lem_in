/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:36:59 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 18:41:29 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_viewer.h"

int			main(void)
{
	t_data		data;

	if (!(data.input = get_input(0, BUFFMAX)))
		return (-1);
	if (!(data.moves = get_moves(data.input)) ||
		get_antfarm(&data.antfarm, data.input) == -1)
		return (-1);
	if (init_mlx(&data.mlx, 1000, 1000, "LEM_IN 2018") == -1)
		return (ft_put_err("init_mlx failed\n"));
	if (load_img(&data.imgs.room, data.mlx.mlx, "xpm/room.xpm") == -1)
		return (-1);
	if (load_img(&data.imgs.ant, data.mlx.mlx, "xpm/ant.xpm") == -1)
		return (-1);
	init_print(&data);
	if (init_ants_viewer(&data) == -1)
		return (ft_put_err("init_ants failed"));
	mlx_loop_hook(data.mlx.mlx, loop_hook, &data);
	mlx_key_hook(data.mlx.win, key_hook, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
