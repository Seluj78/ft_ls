/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:33:28 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/01 15:13:38 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			majorminor(struct stat *sb, char filetype, size_t *max)
{
	(filetype == 'c' || filetype == 'b') ? ft_printf("   %lld, %lld ", \
			major(sb->st_rdev), minor(sb->st_rdev)) : ft_print_nb((max[1] - \
				ft_nblen_ll(sb->st_size)), sb->st_size);
}

void			split(t_save **go, char *path, size_t *max, int *arg)
{
	if (save_helper(go, path, max, arg) == -1)
		free(max);
	else
		ft_printf("ft_ls : %s: %s\n", path, strerror(errno));
}

void			hwait(t_fold *wait, int *arg)
{
	while (wait)
	{
		ft_printf("\n%s\n", wait->path);
		save_ls(wait->path, arg);
		wait = free_listt(wait);
	}
}
