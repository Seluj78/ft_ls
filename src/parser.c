/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:22:52 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 11:51:33 by blucas           ###   ########.fr       */
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
