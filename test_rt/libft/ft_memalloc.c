/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 08:46:17 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/24 08:46:19 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	mem = ft_x_malloc(sizeof(char) * size);
	if (mem == NULL)
		return (0);
	ft_memset(mem, 0, size);
	return (mem);
}
