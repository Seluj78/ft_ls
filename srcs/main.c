/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:32:46 by blucas            #+#    #+#             */
/*   Updated: 2017/02/21 13:26:14 by jlasne           ###   ########.fr       */
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

//FEATURES :
//tri t r
//readlink pour liens (ln -s toto; ft_ls -l n'affche rien, ./ft_ls toto = segfault, ./ft_ls -l toto - segfault
//faire un perror quand appel system fail (perror + errno)
//Ne pas afficher le poids dans major minmor /dev
//ft_ls ne quitte jamais sauf en cas de illegal option. Sinon il passe a la suite

//ERRORS/BUGS
//segfault when impossible to access dir (/dev/fd/3 for example)
//./ft_ls srcs Makefile = segfault
//leaks

//GESTION OPTIONS
//./ft_ls ""
//./ft_ls "- a" == exit_failure
//./ft_ls /dev -a = segfault
//./ft_ls -a -- srcs
//gestion de -- (fin de flag = tout ce qui est apres est gere comme dossier)

//Dans l'odre : Erreur, fichier, repertoire (ordre par option passe)
//exemple : ls tutu srcs Makefile

//Optionnel :
//Allignement majorminor

//bonus easy
//ls -s1
//ls -g
//ls -G
//ls -o
