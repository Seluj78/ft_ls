/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:02:11 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/27 16:21:36 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_time(time_t time)
{
	char *oktime;

	oktime = ft_strsub(ctime(&time), 4, ft_strlen(ctime(&time)) - 13);
	ft_printf(" %s", oktime);
	ft_strdel(&oktime);
}

static void		printfile(char *str, unsigned char type, mode_t st_mode)
{
	if (type == 4)
	{
		ft_putstr(" \e[0;96m");
		ft_putstr(str);
		ft_putstr("\e[0m\n");
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
		ft_putstr("\e[0m\n");
	}
	else
	{
		ft_putstr(" \e[0m");
		ft_putstr(str);
		ft_putstr("\e[0m\n");
	}
}

static void		print_lnkabout(char *fpath)
{
	int		path_size;
	char buf[1024];

	path_size = readlink(fpath, buf, 1024);
	if (path_size > 0)
	{
		fpath[path_size] = '\0';
		ft_printf(" -> %s", buf);
	}
	ft_putchar('\n');
}

void			show_l(char *str, unsigned char type, char *path, size_t *max)
{
	struct stat	sb;
	char		filetype;
	char		*tmp;

	if (path == NULL)
		path = "./";
	tmp = ft_strjoin_sep(path, "/", str);
	if (lstat(tmp, &sb))
	{
		ft_strdel(&tmp);
		ft_printf("ft_ls : %s : %s\n", path, strerror(errno));
		return ;
	}
	filetype = lsperms(sb.st_mode);
	if (filetype == '!')
		return ;
	printspaces(max[2] - ft_nblen(sb.st_nlink) + 2);
	ft_putnbr(sb.st_nlink);
	print_user_info(sb.st_uid, max, str);
	if (filetype == 'c' || filetype == 'b')
		ft_printf("   %d, %d ", major(sb.st_dev), minor(sb.st_dev));
	else
	{
		printspaces(max[1] - ft_nblen_ll(sb.st_size));
		ft_putnbr_ll(sb.st_size);
	}
	print_time(sb.st_mtime);
	printfile(str, type, sb.st_mode);
	if (S_ISLNK(sb.st_mode))
		print_lnkabout(tmp);
	ft_strdel(&tmp);
}
