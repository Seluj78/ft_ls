/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:50:34 by blucas            #+#    #+#             */
/*   Updated: 2016/11/12 11:55:54 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *alst;
	while (tmp)
	{
		del(tmp->content, tmp->content_size);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*alst = NULL;
}
