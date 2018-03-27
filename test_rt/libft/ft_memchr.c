/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:05:53 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/24 12:05:54 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *chr;

	chr = (unsigned char *)s;
	while (n)
	{
		if (*chr == (unsigned char)c)
			return (chr);
		chr++;
		n--;
	}
	return (NULL);
}
