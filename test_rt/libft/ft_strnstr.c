/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:54:35 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/23 12:54:37 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_test(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (big[j] && little[i] && j < len)
	{
		if (big[j] == little[i])
		{
			while (big[j] == little[i] && j < len)
			{
				i++;
				j++;
				if (!little[i])
					return ((char *)(big + (j - i)));
			}
			j -= i;
			i = 0;
		}
		j++;
	}
	return (NULL);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	return ((char*)ft_test(big, little, len));
}
