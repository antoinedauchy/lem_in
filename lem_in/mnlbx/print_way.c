/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:11:34 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/23 20:35:51 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

void				print_way(t_coord a, t_coord b, int width, t_img img)
{
	t_poly		way;
	int			angle;
	double		a_angle;
	double		b_angle;

	angle = get_angle(a.x - b.x, a.y - b.y);
	a_angle = ((double)angle + 90.0) * 3.1415 / 180.0;
	b_angle = (((double)angle + 90.0) - 180.0) * 3.1415 / 180.0;
	way.a.x = a.x + (width / 2) * cos(a_angle);
	way.a.y = a.y - (width / 2) * sin(a_angle);
	way.a.color = a.color;
	way.c.x = a.x + (width / 2) * cos(b_angle);
	way.c.y = a.y - (width / 2) * sin(b_angle);
	way.c.color = a.color;
	way.b.x = b.x + (width / 2) * cos(a_angle);
	way.b.y = b.y - (width / 2) * sin(a_angle);
	way.b.color = b.color;
	way.d.x = b.x + (width / 2) * cos(b_angle);
	way.d.y = b.y - (width / 2) * sin(b_angle);
	way.d.color = b.color;
	print_polygone(way, img);
}
