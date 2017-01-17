/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:02:48 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 15:24:54 by blucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>

int				*arg_parser(char *str, int *arg);
int				*ft_setint(int size);
void			ft_ls(char *path, int *arg);
void			save_ls(char *pat, int *arg);
void			main_ls(char *path, int *arg);

typedef struct s_fold
{
	char *path;
	struct s_fold *next;
}			t_fold;

#endif
