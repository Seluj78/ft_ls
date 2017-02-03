/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:06:20 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/03 15:24:01 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

static int filetypeletter(int mode)
{
	char    c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
	{
		c = '?';
	}
	return(c);
}

static char *lsperms(int mode)
{
	static const char *rwx[] = {"---", "--x", "-w-", "-wx",
		"r--", "r-x", "rw-", "rwx"};
	static char bits[11];

	bits[0] = filetypeletter(mode);
	strcpy(&bits[1], rwx[(mode >> 6)& 7]);
	strcpy(&bits[4], rwx[(mode >> 3)& 7]);
	strcpy(&bits[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	bits[10] = '\0';
	return(bits);
}
void	printspaces(int nb)
{
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
	}
}

void	print_user_group(gid_t gid)
{
	struct	group *gr;

	gr = getgrgid(gid);
	ft_putstr("  ");
	ft_putstr(gr->gr_name);
}

void	print_user_info(uid_t uid, size_t *max, char *str)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	printspaces(max[0] - ft_strlen(str));
	ft_putstr("  ");
	print_user_group(pwd->pw_gid);
}

void	print_time(time_t time)
{
	char *oktime;

	oktime = ft_strnew(ft_strlen(ctime(&time)) - 10);
	oktime = ft_strsub(ctime(&time), 4, ft_strlen(ctime(&time)) - 13);
	ft_putchar(' ');
	ft_putstr(oktime);
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

void	ft_putnbr_ll(long long n)
{
	if (n == -9223372036854775807 - 1)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int		ft_nblen_ll(long long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		if (n == -9223372036854775807 - 1)
			return (20);
		n = -n;
		len = ft_nblen_ll(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_nblen_ll(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}

void	show_l(char *str, unsigned char type, char *path, size_t *max)
{
	//	ft_putstr(ft_strjoin_sep(path, "/", str));
	//	ft_putchar('\n');
	struct stat sb;

	if (path == NULL)
		path = "./";
	stat(ft_strjoin_sep(path, "/", str), &sb);
	/*ft_putstr("Actual : ");
	  ft_putnbr(ft_strlen(str));
	  ft_putstr("\nmax : ");
	  ft_putnbr(max[0]);
	  ft_putchar('\n');*/
	ft_putstr(lsperms(sb.st_mode));
	printspaces(max[2] - ft_nblen_ll(sb.st_nlink) + 2);
	ft_putnbr(sb.st_nlink);
	print_user_info(sb.st_uid, max, str);
	printspaces(max[1] - ft_nblen_ll(sb.st_size) + 2);
	ft_putnbr_ll(sb.st_size);
	print_time(sb.st_mtime);
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
