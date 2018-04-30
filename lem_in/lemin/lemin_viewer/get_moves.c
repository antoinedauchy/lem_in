/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 04:20:14 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/23 21:14:16 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_viewer.h"

char			**get_moves(char **input)
{
	int			n;

	n = 0;
	while (input[n])
		n += 1;
	n -= 1;
	while (n >= 0 && ft_strcmp("", input[n]))
		n -= 1;
	if (n == -1)
	{
		ft_put_err("No moves data");
		return (NULL);
	}
	free(input[n]);
	input[n] = NULL;
	return (&input[n + 1]);
}
