/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:02:11 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/01 14:34:46 by jlasne           ###   ########.fr       */
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
	char	buf[1024];

	path_size = readlink(fpath, buf, 1024);
	buf[path_size] = '\0';
	ft_printf(" -> %s\n", buf);
}

void			ft_print_nb(int spaces, long long int nb)
{
	printspaces(spaces);
	ft_putnbr_ll(nb);
}

void			show_l(char *str, unsigned char type, char *path, size_t *max)
{
	struct stat	sb;
	char		filetype;
	char		*tmp;

	tmp = ft_strjoin_sep(path, "/", str);
	if (lstat(tmp, &sb))
	{
		ft_strdel(&tmp);
		ft_printf("ft_ls : %s : %s\n", path, strerror(errno));
		return ;
	}
	filetype = lsperms(sb.st_mode);
	if (filetype == '!')
	{
		ft_strdel(&tmp);
		return ;
	}
	ft_print_nb((max[2] - ft_nblen(sb.st_nlink) + 2), sb.st_nlink);
	print_user_info(sb.st_uid, max, str);
	majorminor(&sb, filetype, max);
	print_time(sb.st_mtime);
	printfile(str, type, sb.st_mode);
	if (S_ISLNK(sb.st_mode))
		print_lnkabout(tmp);
	ft_strdel(&tmp);
}
