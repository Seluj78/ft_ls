/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:02:49 by blucas            #+#    #+#             */
/*   Updated: 2016/11/11 18:11:38 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		k;

	i = 0;
	while (big[i] && i < len)
	{
		k = 0;
		while (big[i + k] == little[k] && i + k < len && little[k])
			k++;
		if (!little[k])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
