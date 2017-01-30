/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:22:52 by blucas            #+#    #+#             */
/*   Updated: 2017/01/30 10:03:51 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	check_flags(char flag)
{
	if (flag == 'R'
			|| flag == 'l'
			|| flag == 'r'
			|| flag == 'a'
			|| flag == 't')
		return (1);
	return (0);
}

static void	wrong_flags(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
}

int			*arg_parser(char *str, int *arg)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (check_flags(str[i]) == 0)
		{
			wrong_flags(str[i]);
			return (NULL);
		}
		i++;
	}
	arg[0] = ((ft_strchr(str, 'R')) ? 1 : arg[0]);
	arg[1] = ((ft_strchr(str, 'a')) ? 1 : arg[1]);
	arg[2] = ((ft_strchr(str, 'l')) ? 1 : arg[2]);
	arg[3] = ((ft_strchr(str, 't')) ? 1 : arg[3]);
	arg[4] = ((ft_strchr(str, 'r')) ? 1 : arg[4]);
	return (arg);
}


