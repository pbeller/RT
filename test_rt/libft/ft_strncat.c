/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:53:39 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/23 12:53:42 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*result;

	i = 0;
	result = s1;
	while (*s1)
		s1++;
	while (*s2 && i++ < n)
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return (result);
}
