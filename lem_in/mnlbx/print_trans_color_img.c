/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_trans_color_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:44:28 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 04:51:45 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

static void		copy_pxl(t_img dest, t_img src,
					t_coord pos_dest, t_coord pos_src)
{
	int		pxl_src;
	int		pxl_dest;

	pxl_src = pos_src.x * 4 + pos_src.y * src.sizeline;
	pxl_dest = pos_dest.x * 4 + pos_dest.y * dest.sizeline;
	if ((unsigned char)src.data[pxl_src + 0] == pos_src.color % 0x100 &&
		(unsigned char)src.data[pxl_src + 1] == pos_src.color / 0x100 % 0x100 &&
		(unsigned char)src.data[pxl_src + 2] == pos_src.color / 0x10000)
		return ;
	else
		put_pxl_img(pos_dest, dest);
}

void			print_trans_color_img(t_img dest, t_img src,
					t_coord pos, t_coord size)
{
	int		x;
	int		y;
	t_coord	pos_src;
	t_coord	pos_dest;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			pos_src.x = x * src.lenght / size.x;
			pos_src.y = y * src.height / size.y;
			pos_src.color = pos.color;
			pos_dest.x = pos.x + x;
			pos_dest.y = pos.y + y;
			pos_dest.color = size.color;
			copy_pxl(dest, src, pos_dest, pos_src);
			x += 1;
		}
		y += 1;
	}
}
