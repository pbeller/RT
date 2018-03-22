/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:55:06 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/23 12:55:10 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strrev(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = (char *)ft_x_malloc(sizeof(char) * ft_strlen(str));
	if (dest == NULL)
		return (NULL);
	while (str[i])
		i++;
	i = i - 1;
	while (i >= 0)
	{
		dest[j] = str[i];
		j++;
		i--;
	}
	dest[j + 1] = '\0';
	return (dest);
}
