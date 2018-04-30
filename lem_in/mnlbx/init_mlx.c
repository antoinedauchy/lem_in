/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:32:24 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 04:42:04 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

int			init_img(t_img *img, void *mlx, int lenght, int height)
{
	if (!(img->img = mlx_new_image(mlx, lenght, height)))
		return (-1);
	if (!(img->data = mlx_get_data_addr(img->img, &img->bpb,
			&img->sizeline, &img->endian)))
		return (-1);
	img->lenght = lenght;
	img->height = height;
	return (0);
}

int			load_img(t_img *img, void *mlx, char *name)
{
	if (!(img->img = mlx_xpm_file_to_image(mlx, name,
			&img->lenght, &img->height)))
		return (-1);
	if (!(img->data = mlx_get_data_addr(img->img, &img->bpb,
			&img->sizeline, &img->endian)))
		return (-1);
	return (0);
}

int			init_mlx(t_mlx *data, int lenght_win, int height_win, char *title)
{
	if (!(data->mlx = mlx_init()))
		return (-1);
	if (!(data->win = mlx_new_window(data->mlx, lenght_win,
					height_win, title)))
		return (-1);
	if (init_img(&data->img, data->mlx, lenght_win, height_win) == -1)
		return (-1);
	return (0);
}
