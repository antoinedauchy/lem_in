/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_polygone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:22:06 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 04:42:46 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

void		get_line_data(t_coord a, t_coord b, t_line *line)
{
	line->dist_x = a.x - b.x;
	line->dist_y = a.y - b.y;
	line->nb = line->dist_x;
	line->dist = line->dist_x;
	if (ft_abs(line->dist_y) > ft_abs(line->dist_x))
	{
		line->nb = line->dist_y;
		line->dist = line->dist_y;
	}
}

void		get_next_point(t_coord a, t_coord b, t_line *l, t_coord *p)
{
	p->x = b.x + (l->nb * l->dist_x) / l->dist;
	p->y = b.y + (l->nb * l->dist_y) / l->dist;
	p->color = get_color(l->nb, a.color, b.color, l->dist);
}

void		print_polygone(t_poly poly, t_img img)
{
	t_coord	p1;
	t_coord p2;
	t_line	line1;
	t_line	line2;
	int		bigger;

	get_line_data(poly.a, poly.b, &line1);
	get_line_data(poly.c, poly.d, &line2);
	bigger = 1;
	if (ft_abs(line2.nb) > ft_abs(line1.nb))
		bigger = 2;
	print_line(poly.a, poly.c, img);
	if (!line1.nb && !line2.nb)
		return ;
	while (line1.nb && line2.nb)
	{
		if (bigger == 1 && (line1.nb += (line1.nb > 0 ? -1 : 1)))
			line2.nb = (line1.nb * line2.dist) / line1.dist;
		else if (bigger == 2 && (line2.nb += (line2.nb > 0 ? -1 : 1)))
			line1.nb = (line2.nb * line1.dist) / line2.dist;
		get_next_point(poly.a, poly.b, &line1, &p1);
		get_next_point(poly.c, poly.d, &line2, &p2);
		print_line(p1, p2, img);
	}
	print_line(poly.b, poly.d, img);
}
