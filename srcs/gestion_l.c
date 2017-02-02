/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:06:20 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/02 12:51:49 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>



/*
   void	print_perms(struct stat *sb)
   {
   printf( (S_ISDIR(sb->st_mode)) ? "d" : "-");
   printf( (sb->st_mode & S_IRUSR) ? "r" : "-");
   printf( (sb->st_mode & S_IWUSR) ? "w" : "-");
   printf( (sb->st_mode & S_IXUSR) ? "x" : "-");
   printf( (sb->st_mode & S_IRGRP) ? "r" : "-");
   printf( (sb->st_mode & S_IWGRP) ? "w" : "-");
   printf( (sb->st_mode & S_IXGRP) ? "x" : "-");
   printf( (sb->st_mode & S_IROTH) ? "r" : "-");
   printf( (sb->st_mode & S_IWOTH) ? "w" : "-");
   printf( (sb->st_mode & S_IXOTH) ? "x" : "-");
   }*/

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
	printf("  %s", gr->gr_name);
}

void	print_user_info(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	printf(" %s", pwd->pw_name);
	print_user_group(pwd->pw_gid);
}

void	print_time(time_t time)
{
	char *oktime;

	oktime = ft_strnew(ft_strlen(ctime(&time)) - 10);
	oktime = ft_strsub(ctime(&time), 4, ft_strlen(ctime(&time)) - 13);
	printf(" %s", oktime);
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

void		show_l(char *str, unsigned char type, char *path, t_save *go)
{
	//	ft_putstr(ft_strjoin_sep(path, "/", str));
	//	ft_putchar('\n');

	struct stat sb;

	if (path == NULL)
		path = "./";
	stat(ft_strjoin_sep(path, "/", str), &sb);
	if (ft_strlen(str) > go->max_l_name)
		go->max_l_name = ft_strlen(str);
	if (ft_nblen(sb.st_size) > go->max_l_size)
		go->max_l_size = ft_nblen(sb.st_size);
	if (ft_nblen(sb.st_nlink) > go->max_l_links)
		go->max_l_links = ft_nblen(sb.st_nlink);
	//if (type == 4)
	//	printf("d");
	//print_perms(&sb);
	printf("%s", lsperms(sb.st_mode));
	if (ft_nblen(sb.st_nlink) > 1)
		printspaces(5 - ft_nblen(sb.st_nlink));
	else
		printf("    ");
	printf("%d", sb.st_nlink);
	print_user_info(sb.st_uid);
	printspaces((go->max_l_size + 2) - ft_nblen(sb.st_size));
	printf("%lld", sb.st_size);
	print_time(sb.st_mtime);
	if (type == 4)
		printf(" \e[0;96m%s \e[0m\n", str);
	else
		printf("\e[0m %s\e[0m\n", str);


	//printf("ft_ls: %s: No such file or directory\n", str);
}
