/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:08:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/23 16:37:55 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nblen_l(long int n)
{
	size_t		len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = ft_nblen_l(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_nblen_l(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}
