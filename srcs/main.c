/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:32:46 by blucas            #+#    #+#             */
/*   Updated: 2017/02/24 14:36:55 by jlasne           ###   ########.fr       */
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

/*
**FEATURES :
**tri t r
**ERRORS/BUGS
**leaks
**
**GESTION OPTIONS
**./ft_ls "- a" == exit_failure
**./ft_ls -a -- srcs
**gestion de -- (fin de flag = tout ce qui est apres est gere comme dossier)
**
**Dans l'odre de display : Erreur, fichier, repertoire (ordre par option passe)
**./ft_ls srcs Makefile = Pas dans le bon ordre
**ft_ls quitte jamais sauf en cas de illegal option. Sinon il passe a la suite
**exemple : ls tutu srcs Makefile
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
