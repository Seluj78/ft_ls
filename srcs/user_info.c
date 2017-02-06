/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:27:19 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/06 14:05:30 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	print_user_group(gid_t gid, size_t *max)
{
	struct	group *gr;

	gr = getgrgid(gid);
	ft_putstr(gr->gr_name);
	printspaces(max[4] - ft_strlen(gr->gr_name));
	ft_putstr("  ");
}

void		print_user_info(uid_t uid, size_t *max, char *str)
{
	struct passwd *pwd;
	(void)max;
	(void)str;

	pwd = getpwuid(uid);
	ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	printspaces(max[3] - ft_strlen(pwd->pw_name));
	ft_putstr("  ");
	print_user_group(pwd->pw_gid, max);
}

char *get_username(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	return (pwd->pw_name);
}

char *get_groupname(uid_t uid)
{
	struct passwd *pwd;
	struct group *grp;

	pwd = getpwuid(uid);
	grp = getgrgid(pwd->pw_gid);
	return (grp->gr_name);
}
