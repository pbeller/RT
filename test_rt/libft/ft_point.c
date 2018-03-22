/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:01:21 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/02 13:04:36 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_point		*ft_point(int x, int y)
{
	t_point *pt;

	pt = (t_point *)ft_x_malloc(sizeof(t_point));
	pt->x = x;
	pt->y = y;
	return (pt);
}
