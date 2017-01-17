/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:14:31 by blucas            #+#    #+#             */
/*   Updated: 2016/11/11 12:02:13 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		size;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		tab = (char *)malloc(sizeof(char) * size);
		if (!tab)
			return (NULL);
		while (*s1)
			tab[i++] = *(s1++);
		while (*s2)
			tab[i++] = *(s2++);
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
