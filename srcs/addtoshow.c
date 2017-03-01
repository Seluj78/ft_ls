/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtoshow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:29:00 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/01 16:18:06 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			condtri(t_save *cond1, t_save *cond2, int *arg)
{
	if (arg[3] == 1 && arg[4] == 0)
	{
		if (cond1->time < cond2->time)
			return (1);
	}
	else if (arg[3] == 1 && arg[4] == 1)
	{
		if (cond1->time > cond2->time)
			return (1);
	}
	else if (arg[3] == 0 && arg[4] == 1)
	{
		if (ft_strcmp(cond1->name, cond2->name) < 0)
			return (1);
	}
	else
	{
		if (ft_strcmp(cond1->name, cond2->name) > 0)
			return (1);
	}
	return (0);
}

t_save		*add_helper(t_save *go, t_save *new, int *arg)
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
			if (condtri(go, new, arg))
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

t_save		*addtoshow(dirent_t *lecture, char *path, t_save *go, int *arg)
{
	struct stat	what;
	t_save		*new;
	char		*tmpp;

	tmpp = ft_joinpath(path, lecture->d_name);
	new = (t_save*)malloc(sizeof(t_save));
	new->name = ft_strdup(lecture->d_name);
	if (lstat(tmpp, &what))
	{
		ft_strdel(&tmpp);
		ft_printf("ft_ls : %s : %s\n", path, strerror(errno));
		exit(EXIT_FAILURE);
	}
	ft_strdel(&tmpp);
	new->time = what.st_mtime;
	new->type = lecture->d_type;
	new->next = NULL;
	return (add_helper(go, new, arg));
}
