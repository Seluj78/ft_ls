/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:32:58 by blucas            #+#    #+#             */
/*   Updated: 2017/02/27 20:32:56 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

/*
** t_list *file;
** file = (t_list *)malloc(sizeof(t_list) * 1);
** file = order_ls(file, arg);
** show_ls(file);
*/

void		showthat(t_save *go, int *arg, char *path, size_t *max)
{
	if (arg[2] == 1)
	{
		ft_printf("total {:green}%zu{:reset}\n", max[5]);
	}
	while (go != NULL)
	{
		if (arg[2] == 1)
		{
			show_l(go->name, go->type, path, max);
			go = go->next;
		}
		else
		{
			show(go->name, go->type);
			go = go->next;
		}
	}
}

void		show(char *str, unsigned char type)
{
	if (type == 2)
		ft_putstr("\e[0;34;43m");
	if (type == 4)
		ft_putstr("\e[0;96m");
	if (type == 10)
		ft_putstr("\e[35m");
	ft_printf("%s{:reset}\n", str);
}

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxtlst;

	lst = *alst;
	while (lst)
	{
		nxtlst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxtlst;
	}
	*alst = NULL;
}

void		free_list(t_save *go)
{
	t_save *tmp;
	t_save *prev;

	tmp = go;
	while (tmp != NULL)
	{
		free(tmp->name);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}
