/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:32:46 by blucas            #+#    #+#             */
/*   Updated: 2017/02/21 13:17:58 by jlasne           ###   ########.fr       */
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
				main_ls(argv[i - 1], arg);
			}
		}
	}
	else
		main_ls(".", arg);
	if (ok == 1 && argc > 1)
		main_ls(".", arg);
	return (0);
}

//leaks
//tri t r
//segfault when impossible to access dir (/dev/fd/3 for example)
//faire un perror quand appel system fail
//./ft_ls ""
//perror + errno
//./ft_ls "- a" == exit_failure
//readlink pour liens (ln -s toto; ft_ls -l n'affche rien, ./ft_ls toto = segfault, ./ft_ls -l toto - segfault
//./ft_ls srcs Makefile = segfault
//
//Ne pas afficher le poids dans major minmor /dev
//
//Dans l'odre : Erreur, fichier, repertoire (ordre par option passe)
//exemple : ls tutu srcs Makefile
//Optionnel : Allignement majorminor
//
//./ft_ls /dev -a
//./ft_ls -a -- srcs
//gestion de -- (fin de flag = tout ce qui est apres est gere comme dossier)
//
//
//bonus easy
//ls -s1
//ls -g
//ls -G
//ls -o
