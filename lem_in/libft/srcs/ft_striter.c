/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:54:28 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 01:39:51 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_striter(char *s, void (*f)(char*i))
{
	int	n;

	n = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[n] != '\0')
	{
		f(&(s[n]));
		n++;
	}
}