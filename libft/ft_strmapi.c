/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:09:49 by blucas            #+#    #+#             */
/*   Updated: 2016/11/11 12:04:44 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab;
	char			*cpy;
	unsigned int	i;

	i = 0;
	if (s && *s)
	{
		tab = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!tab)
			return (NULL);
		cpy = tab;
		while (*s)
		{
			tab[i] = f(i, *(char *)s);
			s++;
			i++;
		}
		tab[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
