/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:53:24 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 03:04:02 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "antfarm.h"

int			get_nb_ants(char *str)
{
	int		n;
	int		nb;

	n = 0;
	nb = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		nb = nb * 10 + str[n] - '0';
		if (nb > 10000)
			return (ft_put_err("antfarm can't contain more than 10000 ants"));
		n += 1;
	}
	if (str[n] != '\0' || !nb)
		return (-1);
	return (nb);
}
