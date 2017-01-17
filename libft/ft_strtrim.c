/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:14:47 by blucas            #+#    #+#             */
/*   Updated: 2016/11/28 18:35:40 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_emptystring(void)
{
	char	*tab;

	tab = (char *)malloc(sizeof(char) * 1);
	if (!tab)
		return (NULL);
	*tab = '\0';
	return (tab);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		size;
	char	*tab;
	int k;

	k = 0;
	i = 0;
	if (s)
	{
		size = ft_strlen(s);
		while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
			i++;
		if (s[i] == '\0')
			return (ft_emptystring());
		while (s[size - 1] == ' ' || s[size - 1] == '\t' || s[size - 1] == '\n')
			size--;
		tab = (char *)malloc(sizeof(char) * (size - i + 1));
		if (!tab)
			return (NULL);
		while (i < size)
			tab[k++] = s[i++];
		tab[k] = '\0';
		return (tab);
	}
	return (NULL);
}
