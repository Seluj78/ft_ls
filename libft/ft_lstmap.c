/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:29:31 by blucas            #+#    #+#             */
/*   Updated: 2016/11/12 15:45:41 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *retour;
	t_list *cpy;

	retour = NULL;
	cpy = NULL;
	while (lst)
	{
		tmp = (t_list *)malloc(sizeof(t_list) * 1);
		tmp = f(lst);
		if (!retour)
		{
			retour = ft_lstnew(tmp->content, tmp->content_size);
			cpy = retour;
		}
		else
		{
			retour->next = ft_lstnew(tmp->content, tmp->content_size);
			retour = retour->next;
		}
		lst = lst->next;
	}
	return (cpy);
}
