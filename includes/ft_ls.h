/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:02:48 by blucas            #+#    #+#             */
/*   Updated: 2017/02/02 11:52:08 by jlasne           ###   ########.fr       */
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
	size_t max_l_name;
	size_t max_l_size;
	size_t max_l_links;
	struct s_save *next;
}			t_save;

int				*arg_parser(char *str, int *arg);
int				*ft_setint(int size);
void			ft_ls(char *path, int *arg);
void			save_ls(char *pat, int *arg);
void			main_ls(char *path, int *arg);
int				chfake(char *name);
void			show(char *str, unsigned char type);
void			show_l(char *str, unsigned char type, char *path, t_save *go);

#endif
