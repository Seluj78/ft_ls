/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:06:20 by jlasne            #+#    #+#             */
/*   Updated: 2017/01/30 10:20:04 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

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

void		show_l(char *str, unsigned char type)
{
	DIR			*d;
	struct dirent *dir;
	struct stat sb;
	size_t max_l_name;
	size_t max_l_size;
	size_t max_l_links;

	max_l_name = 0;
	max_l_size = 0;
	max_l_links = 0;
	d = opendir(str);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			stat(ft_strjoin_sep(str, "/", dir->d_name), &sb);
			if (ft_strlen(dir->d_name) > max_l_name)
				max_l_name = ft_strlen(dir->d_name);
			if (ft_nblen(sb.st_size) > max_l_size)
				max_l_size = ft_nblen(sb.st_size);
			if (ft_nblen(sb.st_nlink) > max_l_links)
				max_l_links = ft_nblen(sb.st_nlink);
		}
		d = opendir(str);
		while ((dir = readdir(d)) != NULL)
		{
			if (type == 4)
				printf("d");
			print_perms(&sb);
			if (ft_nblen(sb.st_nlink) > 1)
				printspaces(5 - ft_nblen(sb.st_nlink));
			else
				printf("    ");
			printf("%d", sb.st_nlink);
			print_user_info(sb.st_uid);
			printspaces((max_l_size + 2) - ft_nblen(sb.st_size));
			printf("%lld", sb.st_size);
			print_time(sb.st_mtime);
			if (type == 4)
				printf(" {:lcyan}%s {:reset}\n", dir->d_name);
			else
				printf("{:red} %s{:reset}\n", dir->d_name);

		}
		closedir(d);
	}
	else
		printf("ft_ls: %s: No such file or directory\n", str);
}
