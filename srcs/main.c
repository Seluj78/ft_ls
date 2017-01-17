/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:32:46 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 13:22:10 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	int	*arg;
	int	i;
	int	ok;

	arg = NULL;
	i = 0;
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
				ft_putendl("Call LS");
			}
			argv++;
		}
	}
	else
		ft_putendl("Call LS");
	return (0);
}
