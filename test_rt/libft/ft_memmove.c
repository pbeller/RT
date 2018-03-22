/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:32:53 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/24 12:32:56 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && (src + i) != dst)
		i++;
	if ((src + i) == dst)
	{
		i = len;
		while (i > 0)
		{
			*((unsigned char *)(dst + i - 1)) =\
			*((unsigned char *)(src + i - 1));
			i--;
		}
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
		i++;
	}
	return (dst);
}
