/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtoshow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:29:00 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/28 10:14:57 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_save		*add_helper(t_save *go, t_save *new)
{
	int			ko;
	t_save		*tmp;
	t_save		*before;

	ko = 1;
	if (go)
	{
		tmp = go;
		while (go->next && ko == 1)
		{
			if (ft_strcmp(go->name, new->name) > 0)
			{
				ft_swap(go, new, &tmp, before);
				ko = 0;
			}
			before = go;
			go = go->next;
		}
		if (ko == 1)
			go->next = new;
	}
	else
		tmp = new;
	return (tmp);
}

t_save		*addtoshow(char *name, char *path, t_save *go, unsigned char type)
{
	struct stat	what;
	t_save		*new;
	char		*tmpp;

	tmpp = ft_joinpath(path, name);
	new = (t_save*)malloc(sizeof(t_save));
	new->name = name;
	if (lstat(tmpp, &what))
	{
		ft_strdel(&tmpp);
		ft_printf("ft_ls : %s : %s\n", path, strerror(errno));
		exit(EXIT_FAILURE);
	}
	ft_strdel(&tmpp);
	new->time = what.st_mtime;
	new->type = type;
	new->next = NULL;
	return (add_helper(go, new));
}
