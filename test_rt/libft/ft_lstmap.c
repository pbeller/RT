/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:00:29 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/27 16:00:31 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*save;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	save = (*f)(lst);
	new = ft_lstnew(save->content, save->content_size);
	tmp = tmp->next;
	if (!new)
		return (NULL);
	while (tmp)
	{
		save = tmp->next;
		ft_lst_push_back(&new, f(tmp));
		if (!new)
			return (NULL);
		tmp = save;
	}
	return (new);
}
