/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 04:40:11 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 02:56:53 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "antfarm.h"

int			check_nb(char *str, int *n, char car)
{
	if (str[*n] == '-')
		*n += 1;
	while (str[*n] >= '0' && str[*n] <= '9')
		*n += 1;
	if (str[*n] != car)
		return (ft_put_err("Error in room format"));
	return (0);
}
