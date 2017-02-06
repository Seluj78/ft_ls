/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:29:53 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/06 15:33:45 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_putnbr_ll(long long n)
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
