/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:07:03 by blucas            #+#    #+#             */
/*   Updated: 2016/11/12 14:25:23 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (size > 0)
	{
		tab = (char *)malloc(sizeof(char) * (size + 1));
		if (tab != NULL)
		{
			while (i < size)
				tab[i++] = 0;
			tab[i] = 0;
			return (tab);
		}
	}
	else
	{
		tab = (char *)malloc(sizeof(char) * 1);
		if (!tab)
			return (NULL);
		tab[0] = '\0';
	}
	return (tab);
}
