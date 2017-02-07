/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:02:11 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/07 13:04:38 by jlasne           ###   ########.fr       */
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

static void		printfile(char *str, unsigned char type)
{
	if (type == 4)
	{
		ft_putstr(" \e[0;96m");
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

void			show_l(char *str, unsigned char type, char *path, size_t *max)
{
	struct stat	sb;
	char		filetype;

	if (path == NULL)
		path = "./";
	lstat(ft_strjoin_sep(path, "/", str), &sb);
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
		//ft_putstr("  ");
		printspaces(max[1] - ft_nblen_ll(sb.st_size));
	}
	ft_putnbr_ll(sb.st_size);
	print_time(sb.st_mtime);
	printfile(str, type);
}
