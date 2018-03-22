/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:36:11 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/24 09:36:14 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dst;
	char *tmp;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)ft_x_malloc(sizeof(char) * (ft_strlen(s1)\
		+ ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	tmp = dst;
	while (*s1 != '\0')
		*tmp++ = *s1++;
	while (*s2 != '\0')
		*tmp++ = *s2++;
	*tmp = '\0';
	return (dst);
}
