/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:09:03 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/23 16:38:08 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nblen_ll(long long n)
{
	size_t		len;

	len = 0;
	if (n < 0)
	{
		if (n == -9223372036854775807 - 1)
			return (20);
		n = -n;
		len = ft_nblen_ll(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_nblen_ll(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}
