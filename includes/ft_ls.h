/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:02:48 by blucas            #+#    #+#             */
/*   Updated: 2017/01/30 10:18:11 by jlasne           ###   ########.fr       */
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
# include <time.h>

int				*arg_parser(char *str, int *arg);
int				*ft_setint(int size);
void			ft_ls(char *path, int *arg);
void			save_ls(char *pat, int *arg);
void			main_ls(char *path, int *arg);
int				chfake(char *name);
void			show(char *str, unsigned char type);
void			show_l(char *str, unsigned char type);

typedef struct s_fold
{
	char *path;
	struct s_fold *next;
}			t_fold;

typedef struct s_save
{
	char *name;
	int time;
	unsigned char type;
	struct s_save *next;
}			t_save;

#endif
