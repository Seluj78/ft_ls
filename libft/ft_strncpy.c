/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:59:01 by blucas            #+#    #+#             */
/*   Updated: 2016/11/11 12:05:08 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = dst;
	while (*src && i++ < len)
	{
		*dst = *src;
		dst++;
		src++;
	}
	while (i < len)
	{
		*dst = '\0';
		dst++;
		i++;
	}
	return (cpy);
}
