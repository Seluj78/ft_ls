/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:15:36 by jlasne            #+#    #+#             */
/*   Updated: 2017/01/17 13:58:07 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				check_dir(char *dir)
{
	struct stat file_stat;

	if (lstat(dir, &file_stat) < 0)
		return (0);
	return (S_ISDIR(file_stat.st_mode));
}

int				check_chr(char *dir)
{
	struct stat file_stat;

	if (lstat(dir, &file_stat) < 0)
		return (0);
	return (S_ISCHR(file_stat.st_mode));
}

int				check_blk(char *dir)
{
	struct stat file_stat;

	if (lstat(dir, &file_stat) < 0)
		return (0);
	return (S_ISBLK(file_stat.st_mode));
}
int				check_fifo(char *dir)
{
	struct stat file_stat;

	if (lstat(dir, &file_stat) < 0)
		return (0);
	return (S_ISFIFO(file_stat.st_mode));
}
int				check_lnk(char *dir)
{
	struct stat file_stat;

	if (lstat(dir, &file_stat) < 0)
		return (0);
	return (S_ISLNK(file_stat.st_mode));
}
int				check_sock(char *dir)
{
	struct stat file_stat;

	if (lstat(dir, &file_stat) < 0)
		return (0);
	return (S_ISSOCK(file_stat.st_mode));
}

void	ft_ls(char *path, int *arg)
{
	DIR			*d;
	struct dirent *dir;

	if (path == NULL)
		path = "./";
	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] == '.' && arg[1] == 0)
			{
			}
			else
			{
				if (check_dir(dir->d_name) == 1)
				{
					ft_putstr("\e[0;96m");
					ft_putstr(dir->d_name);
					ft_putstr("\e[0m");
					ft_putstr("\n");
				}
				else if (check_chr(dir->d_name) == 1)
				{
					ft_putstr("\e[41m");
					ft_putstr(dir->d_name);
					ft_putstr("\e[0m");
					ft_putstr("\n");
				}
				else if (check_blk(dir->d_name) == 1)
				{
					ft_putstr("\e[43m");
					ft_putstr(dir->d_name);
					ft_putstr("\e[0m");
					ft_putstr("\n");
				}
				else if (check_fifo(dir->d_name) == 1)
				{
					ft_putstr("\e[44m");
					ft_putstr(dir->d_name);
					ft_putstr("\e[0m");
					ft_putstr("\n");
				}
				else if (check_lnk(dir->d_name) == 1)
				{
					ft_putstr("\e[0;35m");
					ft_putstr(dir->d_name);
					ft_putstr("\e[0m");
					ft_putstr("\n");
				}
				else if (check_sock(dir->d_name) == 1)
				{
					ft_putstr("\e[0;32m");
					ft_putstr(dir->d_name);
					ft_putstr("\e[0m");
					ft_putstr("\n");
				}
				else
				{
					ft_putstr(dir->d_name);
					ft_putstr("\n");
				}
			}
		}
		closedir(d);
	}
	else
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putstr(": No such file or directory\n");
	}
}
