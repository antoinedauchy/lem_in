/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 23:26:56 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 04:42:49 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

void		print_square(t_coord pos, t_coord size, int color, t_img img)
{
	int			x;
	int			y;
	t_coord		point;

	y = 0;
	point.color = color;
	while (y < size.y)
	{
		x = 0;
		point.y = y + pos.y;
		while (x < size.x)
		{
			point.x = x + pos.x;
			put_pxl_img(point, img);
			x++;
		}
		y++;
	}
}
