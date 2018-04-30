/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 04:32:04 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 18:35:52 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "antfarm.h"

int			get_coord(int *nb, char *str)
{
	int		n;

	n = 0;
	*nb = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		*nb = *nb * 10 + str[n] - '0';
		if (*nb > 10000)
			return (ft_put_err("Home position can't be larger than 10000"));
		n += 1;
	}
	if (!n)
		return (ft_put_err("Error in coord"));
	return (1);
}
