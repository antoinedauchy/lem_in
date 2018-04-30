/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:36:54 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/15 07:38:36 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

void		fill_image(t_img img, int color)
{
	t_coord		pos;
	t_coord		size;

	pos.x = 0;
	pos.y = 0;
	size.x = img.lenght;
	size.y = img.height;
	print_square(pos, size, color, img);
}
