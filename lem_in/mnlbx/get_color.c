/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:33:00 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/18 06:37:33 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			get_color(int nb, int start, int end, int diff)
{
	int		r;
	int		g;
	int		b;

	r = end / 0x10000 + ((start / 0x10000 - end / 0x10000) * nb) / diff;
	g = end / 0x100 % 0x100 + ((start / 0x100 % 0x100 - end / 0x100 % 0x100) *
							nb) / diff;
	b = end % 0x100 + ((start % 0x100 - end % 0x100) * nb) / diff;
	return (r * 0x10000 + g * 0x100 + b);
}
