/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:15:36 by jlasne            #+#    #+#             */
/*   Updated: 2017/01/17 13:29:52 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
				ft_putstr(dir->d_name);
				ft_putstr("\n");
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
