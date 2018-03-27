/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:31:24 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/26 11:31:26 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*save;

	if (!(*alst))
		return ;
	tmp = *alst;
	while (tmp->next)
	{
		save = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = save;
	}
	ft_lstdelone(&tmp, del);
	(*alst) = NULL;
}
