/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:12:04 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/02 13:14:26 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dpoint	*ft_dpoint(double x, double y)
{
	t_dpoint	*pt;

	pt = (t_dpoint *)ft_x_malloc(sizeof(t_dpoint));
	pt->x = x;
	pt->y = y;
	return (pt);
}
