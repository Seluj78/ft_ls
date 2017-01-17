/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:32:46 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 12:12:51 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	int	*arg;
	int	i;

	arg = NULL;
	i = 0;
	arg = ((argv[1][0] == '-' && argv[1][0]) ?
			arg_parser(argv[1], arg) : ft_setint(5));
	if (argc > 1 && arg)
	{
		while (i < argc)
		{
			argv++;
			i++;
		}
	}
	else if (!arg)
		;
	else
		;
	return (0);
}
