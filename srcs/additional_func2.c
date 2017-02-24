/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:32:58 by blucas            #+#    #+#             */
/*   Updated: 2017/02/24 10:44:10 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*ft_joinpath(char *pat, char *nam)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(pat) + ft_strlen(nam) + 2));
	while (*pat)
		str[i++] = *pat++;
	str[i++] = '/';
	while (*nam)
		str[i++] = *nam++;
	str[i] = '\0';
	return (str);
}

t_fold		*addtolist(t_fold *start, char *path)
{
	t_fold *new;
	t_fold *tmp;

	new = (t_fold*)malloc(sizeof(t_fold) * 1);
	new->path = path;
	new->next = NULL;
	if (start)
	{
		tmp = start;
		while (start->next)
			start = start->next;
		start->next = new;
	}
	else
		tmp = new;
	return (tmp);
}

void		ft_swap(t_save *ok, t_save *new, t_save **tmp, t_save *before)
{
	if (ok == *tmp)
	{
		new->next = ok;
		*tmp = new;
	}
	else
	{
		before->next = new;
		new->next = ok;
	}
}

t_save		*trithat(t_save *go)
{
	t_save			*first;
	char			*tmp;
	int				tmpc;
	unsigned char	tmpd;

	first = go;
	while (go != NULL)
	{
		if (go->next && ft_strcmp(go->name, go->next->name) > 0)
		{
			tmp = go->next->name;
			tmpc = go->next->time;
			tmpd = go->next->type;
			go->next->name = go->name;
			go->next->time = go->time;
			go->next->type = go->type;
			go->name = tmp;
			go->time = tmpc;
			go->type = tmpd;
			go = first;
		}
		else
			go = go->next;
	}
	return (first);
}

int			file_exist(char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer) == 0);
}
