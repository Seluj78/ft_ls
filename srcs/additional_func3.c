/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:33:28 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/01 14:34:05 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			majorminor(struct stat *sb, char filetype, size_t *max)
{
	(filetype == 'c' || filetype == 'b') ? ft_printf("   %lld, %lld ", \
			major(sb->st_rdev), minor(sb->st_rdev)) : ft_print_nb((max[1] - \
				ft_nblen_ll(sb->st_size)), sb->st_size);
}
