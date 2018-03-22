/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:52:05 by pbeller           #+#    #+#             */
/*   Updated: 2016/11/23 12:52:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		nb_lines(const char *s, char c)
{
	int			count;
	int			insub;

	insub = 0;
	count = 0;
	while (*s != '\0')
	{
		if (insub == 1 && *s == c)
			insub = 0;
		else if (insub == 0 && *s != c)
		{
			insub = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static	int		nb_letters(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		words;
	char		**tab;

	if (!s)
		return (NULL);
	i = 0;
	words = nb_lines(s, c);
	tab = (char **)ft_x_malloc(sizeof(*tab) * (words + 1));
	if (tab == NULL)
		return (NULL);
	while (words)
	{
		while (*s == c && *s != 0)
			s++;
		tab[i] = ft_strsub(s, 0, nb_letters(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + nb_letters(s, c);
		i++;
		words--;
	}
	tab[i] = NULL;
	return (tab);
}
