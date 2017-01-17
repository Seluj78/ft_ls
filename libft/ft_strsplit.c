/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:15:06 by blucas            #+#    #+#             */
/*   Updated: 2016/11/11 18:20:14 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *s, char c)
{
	int			i;
	int			found;

	found = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (found == 0)
				i++;
			found = 1;
		}
		else
			found = 0;
		s++;
	}
	return (i);
}

static int		ft_lenwords(char const *s, char c, int *i)
{
	int			size;

	size = 0;
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	while (s[*i] != c && s[*i])
	{
		size++;
		*i = *i + 1;
	}
	if (size > 0)
		size++;
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (s)
	{
		tab = (char **)malloc(sizeof(char *) * ft_countwords(s, c) + 1);
		if (!tab)
			return (NULL);
		if (!*s)
			tab[0] = 0;
		while (s[i] && *s)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				tab[j++] = ft_strsub(s, i, ft_lenwords(s, c, &i) - 1);
		}
		if (*s)
			tab[j] = NULL;
	}
	return (s ? tab : NULL);
}
