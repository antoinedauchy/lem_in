/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:54:57 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 01:40:42 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == c)
			return ((char*)(&(s[n])));
		n--;
	}
	return (NULL);
}