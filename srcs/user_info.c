/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:27:19 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/24 10:34:45 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_user_group(gid_t gid, size_t *max)
{
	struct group *gr;

	errno = 0;
	gr = getgrgid(gid);
	if (errno != 0)
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	ft_putstr(gr->gr_name);
	printspaces(max[4] - ft_strlen(gr->gr_name));
	ft_putstr("  ");
}

void			print_user_info(uid_t uid, size_t *max, char *str)
{
	struct passwd *pwd;

	(void)max;
	(void)str;
	errno = 0;
	pwd = getpwuid(uid);
	if (errno != 0)
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	printspaces(max[3] - ft_strlen(pwd->pw_name));
	ft_putstr("  ");
	print_user_group(pwd->pw_gid, max);
}

char			*get_username(uid_t uid)
{
	struct passwd *pwd;

	errno = 0;
	pwd = getpwuid(uid);
	if (errno != 0)
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	return (pwd->pw_name);
}

char			*get_groupname(uid_t uid)
{
	struct passwd	*pwd;
	struct group	*grp;

	errno = 0;
	pwd = getpwuid(uid);
	if (errno != 0)
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	errno = 0;
	grp = getgrgid(pwd->pw_gid);
	if (errno != 0)
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	return (grp->gr_name);
}
