/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 00:04:26 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/24 19:59:51 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "antfarm/antfarm.h"

# define BUFFMAX		1000

void				write_nodes_distance(t_antfarm *antfarm);
int					init_ants(t_antfarm *antfarm);
int					forward(t_antfarm *antfarm);

#endif
