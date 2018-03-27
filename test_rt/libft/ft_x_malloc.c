/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:34:28 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/19 10:36:47 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_x_malloc(int size)
{
	char *new;

	new = (char *)malloc(size);
	if (!new)
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	(void)size;
	return (new);
}
