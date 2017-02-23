/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:04:52 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/23 17:46:16 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

void	free_chartab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	file_ls(char *path, int *arg, size_t *max)
{
	char	**lol;
	size_t	pathlen;

	lol = ft_strsplit(path, '/');
	pathlen = ft_strlen(path) - ft_strlen(lol[ft_tablen(lol) - 1]);
	if (arg[2] == 1)
	{
		if (ft_tablen(lol) != 1)
		{
			ft_printf("%s:\n", ft_strsub(path, 0, pathlen));
			show_l(lol[ft_tablen(lol) - 1], 0, ft_strsub(path, 0, pathlen), max);
		}
		else
			show_l(lol[ft_tablen(lol) - 1], 0, NULL, max);
	}
	else
	{
		if (ft_tablen(lol) != 1)
			ft_putstr(path);
		else
			ft_putstr(lol[ft_tablen(lol) - 1]);
		ft_putstr("\n\n");
	}
	free_chartab(lol, ft_tablen(lol));
}
