/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:04:52 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/01 13:29:25 by blucas           ###   ########.fr       */
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

//void	file_ls(char *path, size_t *max)
//{
//	char	**lol;
//	size_t	pathlen;
//	char	*tmp;

//	lol = ft_strsplit(path, '/');
//	pathlen = ft_strlen(path) - ft_strlen(lol[ft_tablen(lol) - 1]);
//	tmp = ft_strsub(path, 0, pathlen);
//	if (ft_tablen(lol) != 1)
//	{
//		ft_printf("%s:\n", tmp);
//		show_l(lol[ft_tablen(lol) - 1], 0, tmp, max);
//	}
//	else
//	{
//		show_l(lol[ft_tablen(lol) - 1], 0, "./", max);
//	}
//	free_chartab(lol, ft_tablen(lol));
//	free(tmp);
//}
