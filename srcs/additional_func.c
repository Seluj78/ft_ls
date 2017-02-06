/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:34:31 by blucas            #+#    #+#             */
/*   Updated: 2017/02/06 14:06:54 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	printspaces(int nb)
{
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
	}
}

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

size_t		*ft_setsize_t(int size)
{
	size_t		*tab;
	int		i;

	i = 0;
	tab = (size_t*)malloc(sizeof(size_t) * size);
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

char	*ft_strjoin_sep(char *s1, char *sep, char *s2)
{
	char	*str;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2) + ft_strlen(sep) + 1;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (*s1)
	{
		str[++i] = *s1;
		s1++;
	}
	while (*sep)
	{
		str[++i] = *sep;
		sep++;
	}
	while (*s2)
	{
		str[++i] = *s2;
		s2++;
	}
	str[++i] = '\0';
	return (str);
}

void	ft_putnbr_ll(long long n)
{
	if (n == -9223372036854775807 - 1)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else
		ft_putchar(n + 48);
}

size_t		ft_nblen_ll(long long n)
{
	size_t		len;

	len = 0;
	if (n < 0)
	{
		if (n == -9223372036854775807 - 1)
			return (20);
		n = -n;
		len = ft_nblen_ll(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_nblen_ll(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}
