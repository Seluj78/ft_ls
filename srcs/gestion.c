/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:32:58 by blucas            #+#    #+#             */
/*   Updated: 2017/01/23 10:39:19 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

t_save		*addtoshow(char *name, char *path, t_save *go, unsigned char type)
{
	struct stat what;
	t_save *new;
	t_save *tmp;
	char *tmpp;

	tmpp = ft_joinpath(path, name);
	new = (t_save*)malloc(sizeof(t_save));
	new->name = name;
	lstat(tmpp, &what);
	new->time = what.st_mtime;
	new->type = type;
	new->next = NULL;
	if (go)
	{
		tmp = go;
		while (go->next)
			go = go->next;
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

void	showthat(t_save *go)
{
	while (go != NULL)
	{
		show(go->name, go->type);
		go = go->next;
	}
}

void		show(char *str, unsigned char type)
{
	if (type == 2)
		ft_putstr("\x1b[33m");
	if (type == 4)
		ft_putstr("\x1b[34m");
	if (type == 10)
		ft_putstr("\x1b[36m");
	ft_putstr(str);
	ft_putstr("\x1b[0m");
	ft_putchar('\n');
}

void		save_ls(char *path, int *arg)
{
	DIR *rep;
	struct dirent *lecture;
	t_fold *wait;
	t_save *go;
	go = NULL;
	wait = NULL;
	rep = opendir(path);
	while(rep && (lecture = readdir(rep)))
	{
		if (lecture->d_name[0] != '.' || arg[1] == 1)
		{
			if (lecture->d_type == 4 && arg[0] == 1 && chfake(lecture->d_name))
				wait = addtolist(wait, ft_joinpath(path, lecture->d_name));
			go = addtoshow(ft_strdup(lecture->d_name), path, go, lecture->d_type);
		}
	}
	if (rep)
	{
		go = trithat(go);
		showthat(go);
		closedir(rep);
	}
	while (wait)
	{
		ft_putendl(wait->path);
		save_ls(wait->path, arg);
		wait = wait->next;
	}
}

