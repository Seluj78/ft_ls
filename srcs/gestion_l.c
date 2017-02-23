/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:02:11 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/23 14:52:09 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_time(time_t time)
{
	char *oktime;

	oktime = ft_strnew(ft_strlen(ctime(&time)) - 10);
	oktime = ft_strsub(ctime(&time), 4, ft_strlen(ctime(&time)) - 13);
	ft_putchar(' ');
	ft_putstr(oktime);
}

static void		print_majorminor(dev_t dev)
{
	ft_putnbr(major(dev));
	ft_putstr(", ");
	ft_putnbr(minor(dev));
}

static void		printfile(char *str, unsigned char type, mode_t st_mode)
{
	if (type == 4)
	{
		ft_putstr(" \e[0;96m");
		ft_putstr(str);
		ft_putstr("\e[0m");
	}
	else if (type == 10)
	{
		ft_putstr(" \033[0;35m");
		ft_putstr(str);
		ft_putstr("\e[0m");
	}
	else if (st_mode & S_IXUSR)
	{
		ft_putstr(" \033[0;31m");
		ft_putstr(str);
		ft_putstr("\e[0m");
	}
	else
	{
		ft_putstr(" \e[0m");
		ft_putstr(str);
		ft_putstr("\e[0m");
	}
}

void		print_lnkabout(char *fpath)
{
	int		path_size;
	char	*path_save;

	if (!(path_save = ft_strdup(fpath)))
		return ;
	path_size = readlink(fpath, fpath, 1024);
	if (path_size > 0)
	{
		fpath[path_size] = '\0';
		ft_putstr(" -> ");
		ft_putstr(fpath);
	}
	ft_strcpy(fpath, path_save);
	free(path_save);
}

void			show_l(char *str, unsigned char type, char *path, size_t *max)
{
	struct stat	sb;
	char		filetype;

	if (path == NULL)
		path = "./";
	//ft_putstr(ft_strjoin_sep(path, "/", str));
	if (lstat(ft_strjoin_sep(path, "/", str), &sb))
	{
		ft_putstr("ft_ls : ");
		ft_putstr(path);
		perror(" ");
		ft_putchar('\n');
		return ;
	}
	filetype = lsperms(sb.st_mode);
	printspaces(max[2] - ft_nblen(sb.st_nlink) + 2);
	ft_putnbr(sb.st_nlink);
	print_user_info(sb.st_uid, max, str);
	if (filetype == 'c' || filetype == 'b')
	{
		ft_putstr("   ");
		print_majorminor(sb.st_rdev);
		ft_putchar(' ');
	}
	else
	{
		printspaces(max[1] - ft_nblen_ll(sb.st_size));
		ft_putnbr_ll(sb.st_size);
	}
	print_time(sb.st_mtime);
	printfile(str, type, sb.st_mode);
	if (S_ISLNK(sb.st_mode))
		print_lnkabout(ft_strjoin_sep(path, "/", str));
	ft_putchar('\n');
}
