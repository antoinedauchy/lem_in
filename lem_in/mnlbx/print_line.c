/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:33:36 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 04:42:36 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

int			useless_line(t_coord *a, t_coord *b, t_img img, t_coord *d)
{
	if ((a->x < 0 && b->x < 0) ||
		(a->x >= img.lenght && b->x >= img.lenght) ||
		(a->y < 0 && b->y < 0) ||
		(a->y >= img.height && b->y >= img.height))
		return (-1);
	if (!d->x && !d->y)
		return (put_pxl_img(*a, img) - 1);
	return (0);
}

void		print_line(t_coord a, t_coord b, t_img img)
{
	t_coord		d;
	int			nb;
	t_coord		p;
	int			dist;

	d.x = a.x - b.x;
	d.y = a.y - b.y;
	if (useless_line(&a, &b, img, &d) == -1)
		return ;
	dist = d.x;
	if (ft_abs(d.y) > ft_abs(d.x) && (nb = d.y))
		dist = d.y;
	nb = dist;
	put_pxl_img(a, img);
	while (nb > 0 ? --nb : ++nb)
	{
		p.x = b.x + (nb * d.x) / dist;
		p.y = b.y + (nb * d.y) / dist;
		p.color = get_color(nb, a.color, b.color, dist);
		put_pxl_img(p, img);
	}
	put_pxl_img(b, img);
}
