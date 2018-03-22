/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:05:23 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/24 10:05:25 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		start;
	int		size;
	int		end;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	end = size - 1;
	start = 0;
	while (start <= size && ft_is_white_space(s[start]) == 1)
		start++;
	while (end >= start && ft_is_white_space(s[end]) == 1)
		end--;
	size = size - (ft_strlen(s) - end) - start + 1;
	new = ft_strsub(s, start, size);
	return (new);
}
