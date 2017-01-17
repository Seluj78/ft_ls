/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:58:04 by blucas            #+#    #+#             */
/*   Updated: 2016/11/08 10:46:22 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *tab;

	tab = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (tab != NULL)
		tab = ft_strcpy(tab, s1);
	else
		return (NULL);
	return (tab);
}
