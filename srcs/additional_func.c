/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:34:31 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 13:52:00 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			*ft_setint(int size)
{
	int		*tab;
	int		i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * size);
	while (i < size && tab)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int			chfake(char *name)
{
	if (name[0] == '.' && !name[1])
		return 0;
	if (name[0] == '.' && name[1] == '.' && !name[2])
		return 0;
	return 1;
}
