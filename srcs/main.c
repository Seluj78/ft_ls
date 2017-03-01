/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:32:46 by blucas            #+#    #+#             */
/*   Updated: 2017/03/01 10:16:11 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	int	*arg;
	int	i;
	int	ok;

	i = 1;
	ok = 1;
	arg = ft_setint(5);
	if (argc > 1)
	{
		while (i++ < argc)
		{
			if (ok == 1 && argv[i - 1][0] == '-' && argv[i - 1][1])
				arg = arg_parser(argv[i - 1], arg);
			else
			{
				ok = 0;
				save_ls(argv[i - 1], arg);
			}
		}
	}
	else
		save_ls(".", arg);
	(ok == 1 && argc > 1) ? save_ls(".", arg) : 0;
	free(arg);
	return (0);
}

t_fold	*free_listt(t_fold *lst)
{
	t_fold *tmp;

	tmp = lst->next;
	free(lst->path);
	free(lst);
	return (tmp);
}

/*
**FEATURES :
**tri t r
**leaks set_size_t
**norme save_ls
**
**./ft_ls "- a" == exit_failure
**./ft_ls -a -- srcs
**gestion de -- (fin de flag = tout ce qui est apres est gere comme dossier)
**
**Dans l'odre de display : Erreur, fichier, repertoire (ordre par option passe)
**./ft_ls srcs Makefile = Pas dans le bon ordre
**
**Optionnel :
**Allignement majorminor
**
**bonus easy
**ls -s1
**ls -g
**ls -G
**ls -o
*/
