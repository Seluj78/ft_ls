/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:32:58 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 15:29:39 by blucas           ###   ########.fr       */
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

int			ft_isdir(char *path)
{
	struct stat what;
	lstat(path, &what);
	if (S_ISDIR(what.st_mode))
		return 1;
	else
		return 0;
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

void		save_ls(char *path, int *arg)
{
	DIR *rep;
	struct dirent *lecture;
	char *tmp;
	t_fold *wait;

	wait = NULL;
	rep = opendir(path);
	while(rep && (lecture = readdir(rep)))
	{
		if (lecture->d_name[0] != '.' || arg[1] == 1)
		{
			tmp = ft_joinpath(path, lecture->d_name);
			if (ft_isdir(tmp) && arg[0] == 1 && ft_strcmp(lecture->d_name, ".") != 0
					&& ft_strcmp(lecture->d_name, "..") != 0)
				wait = addtolist(wait, tmp);
			ft_putendl(lecture->d_name);
		}
	}
	if (rep)
		closedir(rep);
	while (wait)
	{
		ft_putendl(wait->path);
		save_ls(wait->path, arg);
		wait = wait->next;
	}
}
