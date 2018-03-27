/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:01:44 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/26 19:01:46 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*save;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp->next)
	{
		save = tmp->next;
		(*f)(tmp);
		tmp = save;
	}
	(*f)(tmp);
}
