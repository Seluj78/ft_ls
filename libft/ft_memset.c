/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:28:42 by blucas            #+#    #+#             */
/*   Updated: 2017/01/16 12:16:44 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	void		*cpy;

	i = 0;
	cpy = b;
	while (i < len)
	{
		*(char *)b = c;
		b++;
		i++;
	}
	return (cpy);
}
