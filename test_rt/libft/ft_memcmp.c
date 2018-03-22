/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 08:46:36 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/24 08:46:38 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *mem1;
	unsigned char *mem2;

	mem1 = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	while (n--)
	{
		if (*mem1 != *mem2)
			return ((unsigned char)*mem1 - (unsigned char)*mem2);
		mem1++;
		mem2++;
	}
	return (0);
}
