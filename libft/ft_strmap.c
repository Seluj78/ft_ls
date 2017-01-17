/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:09:24 by blucas            #+#    #+#             */
/*   Updated: 2016/11/11 12:04:17 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *tab;
	char *cpy;

	if (s && *s)
	{
		tab = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!tab)
			return (NULL);
		cpy = tab;
		while (*s)
		{
			*tab = f(*(char *)s);
			s++;
			tab++;
		}
		*tab = '\0';
		return (cpy);
	}
	return (NULL);
}
