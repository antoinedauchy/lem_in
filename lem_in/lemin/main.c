/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 00:04:01 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 19:40:37 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_antfarm(char **input)
{
	int	n;

	n = 0;
	while (input[n])
	{
		ft_printf("%s\n", input[n]);
		n += 1;
	}
}

int		main(void)
{
	t_antfarm	antfarm;
	char		**input;

	if (!(input = get_input(0, BUFFMAX)))
		return (-1);
	if (get_antfarm(&antfarm, input) == -1)
		return (-1);
	print_antfarm(input);
	ft_printf("\n");
	if (init_ants(&antfarm) == -1)
		return (-1);
	write_nodes_distance(&antfarm);
	while (forward(&antfarm))
		ft_printf("\n");
	ft_free_2d_tab((void**)input, 1);
	free_antfarm(antfarm);
	return (0);
}
