/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:31:25 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/01 10:37:50 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static size_t		*get_maxif(struct dirent *lecture, size_t *max,
		struct stat sb, int *arg)
{
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
	return (max);
}

static size_t		*get_max(char *path, int *arg)
{
	DIR				*maxl;
	size_t			*max;
	struct dirent	*lecture;
	struct stat		sb;
	char			*tmppath;

	max = ft_setsize_t(6);
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
				break ;
			}
			ft_strdel(&tmppath);
			max = get_maxif(lecture, max, sb, arg);
		}
		closedir(maxl);
	}
	return (max);
}

int					save_helper(t_save **go, char *path, size_t *max, int *arg)
{
	if (file_exist(path))
	{
		if (arg[2] == 1)
		{
			file_ls(path, max);
			return (-1);
		}
		else
			*go = addtoshow(ft_strdup(path), "./", *go, 1);
	}
	else
	{
		ft_printf("ft_ls : %s: %s\n", path, strerror(errno));
		return (-1);
	}
	return (0);
}

void				save_ls(char *path, int *arg)
{
	DIR				*rep;
	struct dirent	*lecture;
	t_fold			*wait;
	t_save			*go;
	char			*tmpstr;
	size_t			*max;

	go = NULL;
	wait = NULL;
	max = ft_setsize_t(6);
	rep = opendir(path);
	if (!rep)
	{
		if (save_helper(&go, path, max, arg) == -1)
		{
			free(max);
			return ;
		}
		else
		{
			ft_printf("ft_ls : %s: %s\n", path, strerror(errno));
			return ;
		}
	}
	while (rep && (lecture = readdir(rep)))
	{
		if (lecture->d_name[0] != '.' || arg[1] == 1)
		{
			if (lecture->d_type == 4 && arg[0] == 1 && chfake(lecture->d_name))
			{
				tmpstr = ft_joinpath(path, lecture->d_name);
				wait = addtolist(wait, tmpstr);
			}
			go = addtoshow(ft_strdup(lecture->d_name), path, go,
					lecture->d_type);
		}
	}
	if (rep)
		closedir(rep);
	free(max);
	max = get_max(path, arg);
	showthat(go, arg, path, max);
	free_list(go);
	while (wait)
	{
		ft_printf("\n%s\n", wait->path);
		save_ls(wait->path, arg);
		wait = free_listt(wait);
	}
	free(max);
}
