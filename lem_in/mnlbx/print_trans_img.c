/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_trans_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:15:37 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 04:43:21 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

void		copy_pxl(t_img dest, t_img src, t_coord pos_dest, t_coord pos_src)
{
	int		pxl_src;
	int		pxl_dest;

	pxl_src = pos_src.x * 4 + pos_src.y * src.sizeline;
	pxl_dest = pos_dest.x * 4 + pos_dest.y * dest.sizeline;
	if ((unsigned char)src.data[pxl_src + 0] == pos_src.color % 0x100 &&
		(unsigned char)src.data[pxl_src + 1] == pos_src.color / 0x100 % 0x100 &&
		(unsigned char)src.data[pxl_src + 2] == pos_src.color / 0x10000)
		return ;
	dest.data[pxl_dest + 0] = src.data[pxl_src + 0];
	dest.data[pxl_dest + 1] = src.data[pxl_src + 1];
	dest.data[pxl_dest + 2] = src.data[pxl_src + 2];
}

void		get_rot(t_coord *point, double angle, double x_rot, double y_rot)
{
	double	rad;
	double	x;
	double	y;

	rad = angle * 3.1415 / 180.0;
	x = (double)point->x;
	y = (double)point->y;
	point->x = (x - x_rot) * cos(rad) - (y - y_rot) * sin(rad) + x_rot;
	point->y = (x - x_rot) * sin(rad) + (y - y_rot) * cos(rad) + y_rot;
}

void		print_trans_img(t_img dest, t_img src, t_coord pos, t_coord size)
{
	int		x;
	int		y;
	t_coord	pos_src;
	t_coord	pos_dest;
	double	rad;

	rad = size.color * 3.1415 / 180.0;
	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			pos_src.x = x * src.lenght / size.x;
			pos_src.y = y * src.height / size.y;
			pos_src.color = pos.color;
			pos_dest.x = pos.x + x;
			pos_dest.y = pos.y + y;
			if (size.color != -1)
				get_rot(&pos_dest, size.color, pos.x + size.x / 2,
						pos.y + size.y / 2);
			copy_pxl(dest, src, pos_dest, pos_src);
		}
	}
}
