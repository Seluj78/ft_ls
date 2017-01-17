/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:22:52 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 11:53:27 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		*arg_parser(char *str, int *arg)
{
	arg = (int * ) malloc(sizeof(int) * 5);
	arg[0] = ((ft_strchr(str, 'R')) ? 1 : 0);
	arg[1] = ((ft_strchr(str, 'a')) ? 1 : 0);
	arg[2] = ((ft_strchr(str, 'l')) ? 1 : 0);
	arg[3] = ((ft_strchr(str, 't')) ? 1 : 0);
	arg[4] = ((ft_strchr(str, 'r')) ? 1 : 0);

	return (arg);
}



static void		act_flag(char flag, t_data *data)
{
	if (flag == 'l')
		data->has_l = TRUE;
	else if (flag == 'r')
		data->has_r = TRUE;
	else if (flag == 'R')
		data->has_maj_r = TRUE;
	else if (flag == 't')
		data->has_t = TRUE;
	else if (flag == 'a')
		data->has_a = TRUE;
}

static void		wrong_flag(char flag)
{
	ft_printf("ft_ls: illegal option -- %c\n", flag);
	ft_printf("usage: ft_ls [-altrR] [file ...]\n");
	exit(1);
}

static int		check_flags(char flag)
{
	if (flag == 'R'
			|| flag == 'l'
			|| flag == 'r'
			|| flag == 'a'
			|| flag == 't')
		return (1);
	return (0);
}

static void		check_opt(char *opt, t_data *data)
{
	int i;

	i = 1;
	while (opt[i] != '\0')
	{
		if (check_flags(opt[i]) == 0)
			wrong_flag(opt[i]);
		else
			act_flag(opt[i], data);
		i++;
	}
}

void			parser(int argc, char **argv, t_data *data)
{
	int		i;
	int		ct;
	char	nf;

	(void)data;
	nf = 0;
	ct = 1;
	while (ct < argc)
	{
		i = 0;
		while (argv[ct][i] != '\0')
		{
			if (argv[1][0] == '-' && argv[1][1] == '-')
				nf = 1;
			else if (argv[1][0] == '-' && argv[1][1] != '\0' && nf == 0)
				check_opt(argv[1], data);
			i++;
		}
		ct++;
	}
}
