/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:04:52 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/27 18:34:33 by jlasne           ###   ########.fr       */
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
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

void	file_ls(char *path, size_t *max)
{
	char	**lol;
	size_t	pathlen;

	lol = ft_strsplit(path, '/');
	pathlen = ft_strlen(path) - ft_strlen(lol[ft_tablen(lol) - 1]);
		if (ft_tablen(lol) != 1)
		{
			ft_printf("%s:\n", ft_strsub(path, 0, pathlen));
			show_l(lol[ft_tablen(lol) - 1], 0, \
					ft_strsub(path, 0, pathlen), max);
		}
		else
			show_l(lol[ft_tablen(lol) - 1], 0, NULL, max);
	free_chartab(lol, ft_tablen(lol));
}
