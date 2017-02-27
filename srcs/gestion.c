/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:32:58 by blucas            #+#    #+#             */
/*   Updated: 2017/02/27 14:55:31 by blucas           ###   ########.fr       */
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

t_save		*addtoshow(char *name, char *path, t_save *go, unsigned char type)
{
	struct stat	what;
	t_save		*new;
	t_save		*tmp;
	char		*tmpp;
	int			ko;
	t_save		*before;

	tmpp = ft_joinpath(path, name);
	new = (t_save*)malloc(sizeof(t_save));
	new->name = name;
	lstat(tmpp, &what);
	ft_strdel(&tmpp);
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
	return (tmp);
}

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

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
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

void free_list(t_save *go)
{
	t_save *tmp;
	t_save *prev;

	tmp = go;
	while(tmp != NULL)
	{
		free(tmp->name);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

void		save_ls(char *path, int *arg)
{
	DIR				*rep;
	DIR				*maxl;
	struct dirent	*lecture;
	struct stat		sb;
	t_fold			*wait;
	t_save			*go;
	size_t			*max;
	char			*tmppath;
	//t_save			*tmp;
	//t_fold			*tmp2;

	go = NULL;
	wait = NULL;
	rep = opendir(path);
	max = ft_setsize_t(6);
	if (!rep)
	{
//		if (file_exist(path))
//		{
//			file_ls(path, arg, max);
//			return ;
//		}
//		else
//		{
			ft_printf("ft_ls : %s: %s\n", path, strerror(errno));
//			return ;
//		}
	}
	while (rep && (lecture = readdir(rep)))
	{
		if (lecture->d_name[0] != '.' || arg[1] == 1)
		{
			if (lecture->d_type == 4 && arg[0] == 1 && chfake(lecture->d_name))
			{
				char *tmpstr = ft_joinpath(path, lecture->d_name);
				wait = addtolist(wait, tmpstr);
			}
			go = addtoshow(ft_strdup(lecture->d_name), path, go,
					lecture->d_type);
		}
	}
	if (rep)
		closedir(rep);
	maxl = opendir(path);
	if (maxl)
	{
		while ((lecture = readdir(maxl)) != NULL)
		{
			tmppath = ft_strjoin_sep(path, "/", lecture->d_name);
			if (lstat(tmppath, &sb))
			{
				ft_strdel(&tmppath);
				ft_printf("ft_ls : %s: %s\n", path, strerror(errno));
				break;
			}
			ft_strdel(&tmppath);
			if (ft_strlen(lecture->d_name) > max[0])
				max[0] = ft_strlen(lecture->d_name);
			if (ft_nblen_ll(sb.st_size) > max[1])
				max[1] = ft_nblen_ll(sb.st_size);
			if (ft_nblen(sb.st_nlink) > max[2])
				max[2] = ft_nblen(sb.st_nlink);
			if (ft_strlen(get_username(sb.st_uid)) > max[3])
				max[3] = ft_strlen(get_username(sb.st_uid));
			if (ft_strlen(get_groupname(sb.st_uid)) > max[4])
				max[4] = ft_strlen(get_groupname(sb.st_uid));
			if (lecture->d_name[0] == '.' && arg[1] == 1)
				max[5] += sb.st_blocks;
			else
			{
				if (lecture->d_name[0] == '.')
					max[5] += 0;
				else
					max[5] += sb.st_blocks;
			}
		}
		closedir(maxl);
	}
	if (rep)
		showthat(go, arg, path, max);
	free_list(go);
	free(max);
	while (wait)
	{
		ft_printf("\n%s\n", wait->path);
		save_ls(wait->path, arg);
		wait = free_listt(wait);
	}
}
