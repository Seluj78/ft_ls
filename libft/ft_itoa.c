/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:15:17 by blucas            #+#    #+#             */
/*   Updated: 2016/11/12 12:44:56 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getsize(long nb)
{
	int		i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	if (nb < 10)
		i++;
	else if (nb > 9)
	{
		while ((nb / 10) >= 1)
		{
			nb = nb / 10;
			i++;
		}
		i++;
	}
	return (i);
}

static void	ft_mycondtion(char **s, int *i, long *val, int size)
{
	if (*val > 9)
	{
		s[0][size - 1 - *i] = *val % 10 + '0';
		*val = *val / 10;
	}
	else
	{
		s[0][size - 1 - *i] = *val + '0';
		*val = -1;
	}
	*i = *i + 1;
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		size;
	long	val;

	i = 0;
	val = n;
	size = ft_getsize(val);
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	if (val < 0)
	{
		val = -val;
		tab[0] = '-';
	}
	while (val >= 0)
		ft_mycondtion(&tab, &i, &val, size);
	if (val == 0)
		tab[i++] = '0';
	tab[size] = '\0';
	return (tab);
}
