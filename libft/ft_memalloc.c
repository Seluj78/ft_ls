/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:06:36 by blucas            #+#    #+#             */
/*   Updated: 2016/11/04 14:06:39 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *aloq;

	aloq = (void *)malloc(sizeof(void) * size);
	if (!aloq)
		return (NULL);
	ft_bzero(aloq, size);
	return (aloq);
}
