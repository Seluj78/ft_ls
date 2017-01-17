/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:32:46 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 11:51:35 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	int *arg;

	arg = NULL;
	arg = ((argv[1][0] == '-' && argv[1][0]) ?
			arg_parser(argv[1], arg) : ft_setint(5));
	if (argc > 1 && arg)
		while (argv)
		{

			argv++;
		}
	}
	else if (!arg)
		;
	else
		ft_ls(".", arg);
	return (0);
}
