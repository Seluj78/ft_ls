/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:15:36 by jlasne            #+#    #+#             */
/*   Updated: 2017/01/17 13:18:54 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ls(char *path, int *arg)
{
	DIR			*d;

	if (path == NULL)
		path = "./";
	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{

			if (dir->d_name[0] == '.' && arg[1] = 1)
			{
			}
			else
				ft_putstr(dir->d_name);
		}
		closedir(d);
	}
	else
		ft_printf("ft_ls: %s: No such file or directory\n", path);
}
