/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:02:35 by blucas            #+#    #+#             */
/*   Updated: 2016/11/11 18:09:48 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		k;

	i = 0;
	while (big[i])
	{
		k = 0;
		while (big[i + k] == little[k] && little[k])
			k++;
		if (!little[k])
			return ((char *)big + i);
		i++;
	}
	if (!*big && !*little)
		return ((char *)big);
	return (NULL);
}
