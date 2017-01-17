/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:11:48 by blucas            #+#    #+#             */
/*   Updated: 2016/11/12 12:39:44 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*point;
	void	*tmp;
	size_t	size;

	point = malloc(sizeof(t_list));
	if (!point)
		return (NULL);
	if (!(content))
	{
		point->content = NULL;
		point->content_size = 0;
		point->next = NULL;
		return (point);
	}
	size = content_size;
	tmp = ft_memalloc(size);
	tmp = ft_memcpy(tmp, content, size);
	point->content = tmp;
	point->content_size = size;
	point->next = NULL;
	return (point);
}
