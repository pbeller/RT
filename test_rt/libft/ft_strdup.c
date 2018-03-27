/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:53:06 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/23 12:53:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(str);
	dest = (char *)ft_x_malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (0);
	while (i <= size)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
