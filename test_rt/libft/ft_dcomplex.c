/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcomplex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:48:22 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/02 13:48:23 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dcomplex	ft_dcomplex(double r, double i)
{
	t_dcomplex	complex;

	complex.r = r;
	complex.i = i;
	return (complex);
}
