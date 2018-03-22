/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:51:04 by pbeller           #+#    #+#             */
/*   Updated: 2017/02/23 13:37:30 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *left, char *right, char free_num)
{
	char	*out;

	out = ft_strjoin(left, right);
	if (free_num == 'l' || free_num == 'b')
		free(left);
	if (free_num == 'r' || free_num == 'b')
		free(right);
	return (out);
}
