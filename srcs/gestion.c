/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:32:58 by blucas            #+#    #+#             */
/*   Updated: 2017/02/03 12:05:57 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>
void	main_ls(char *path, int *arg)
{
	t_list *file;

	file = (t_list *) malloc(sizeof(t_list) * 1);
	save_ls(path, arg);
	//	file = order_ls(file, arg);
	//	show_ls(file);
}

char	*ft_joinpath(char *pat, char *nam)
{
	char *str;
	int i;

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

static char	*ft_strjoin_sep(char *s1, char *sep, char *s2)
{
	char	*str;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2) + ft_strlen(sep) + 1;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (*s1)
	{
		str[++i] = *s1;
		s1++;
	}
	while (*sep)
	{
		str[++i] = *sep;
		sep++;
	}
	while (*s2)
	{
		str[++i] = *s2;
		s2++;
	}
	str[++i] = '\0';
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

t_save		*addtoshow(char *name, char *path, t_save *go, unsigned char type)
{
	struct stat what;
	t_save *new;
	t_save *tmp;
	char *tmpp;
	int ko;
	t_save *before;

	tmpp = ft_joinpath(path, name);
	new = (t_save*)malloc(sizeof(t_save));
	new->name = name;
	lstat(tmpp, &what);
	new->time = what.st_mtime;
	new->type = type;
	new->next = NULL;
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
	free(tmpp);
	return (tmp);
}

t_save		*trithat(t_save *go)
{
	t_save *first;
	char *tmp;
	int tmpc;
	unsigned char tmpd;

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

void	showthat(t_save *go, int *arg, char *path, size_t *max)
{

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
	ft_putstr(str);
	ft_putstr("\e[0m");
	ft_putchar('\n');
}

void		save_ls(char *path, int *arg)
{
	DIR *rep;
	struct dirent *lecture;
	struct stat sb;
	t_fold *wait;
	t_save *go;
	go = NULL;
	wait = NULL;
	rep = opendir(path);
	size_t *max;

	max = ft_setsize_t(3);
	while(rep && (lecture = readdir(rep)))
	{
		if (lecture->d_name[0] != '.' || arg[1] == 1)
		{
			if (lecture->d_type == 4 && arg[0] == 1 && chfake(lecture->d_name))
				wait = addtolist(wait, ft_joinpath(path, lecture->d_name));
			go = addtoshow(ft_strdup(lecture->d_name), path, go, lecture->d_type);
		}
	}
	rep = opendir(path);
	if (rep)
	{
		while ((lecture = readdir(rep)) != NULL)
		{
			stat(ft_strjoin_sep(path, "/", lecture->d_name), &sb);
			if (ft_strlen(lecture->d_name) > max[0])
				max[0] = ft_strlen(lecture->d_name);
			if (ft_nblen(sb.st_size) > max[1])
				max[1] = ft_nblen(sb.st_size);
			if (ft_nblen(sb.st_nlink) > max[2])
				max[2] = ft_nblen(sb.st_nlink);
		}
	}
	if (rep)
	{
		//go = trithat(go);
		showthat(go, arg, path, max);
		closedir(rep);
	}
	while (wait)
	{
		ft_putendl(wait->path);
		save_ls(wait->path, arg);
		wait = wait->next;
	}
}

