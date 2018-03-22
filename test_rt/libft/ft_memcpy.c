/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:57:59 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/23 12:58:00 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*d1;

	if (n == 0)
		return (dst);
	i = 0;
	s1 = (char *)src;
	d1 = (char *)dst;
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (dst);
}
