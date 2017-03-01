/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:02:48 by blucas            #+#    #+#             */
/*   Updated: 2017/03/01 14:35:31 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <stdio.h>

typedef struct			s_fold
{
	char				*path;
	struct s_fold		*next;
}						t_fold;

typedef struct			s_save
{
	char				*name;
	int					time;
	unsigned char		type;
	struct s_save		*next;
}						t_save;

int						*arg_parser(char *str, int *arg);
int						*ft_setint(int size);
size_t					*ft_setsize_t(int size);
void					ft_ls(char *path, int *arg);
void					save_ls(char *pat, int *arg);
void					main_ls(char *path, int *arg);
int						chfake(char *name);
void					show(char *str, unsigned char type);
void					show_l(char *str, unsigned char type, char *path,\
						size_t *max);
char					*ft_strjoin_sep(char *s1, char *sep, char *s2);
char					lsperms(int mode);
void					printspaces(int nb);
void					print_user_info(uid_t uid, size_t *max, char *str);
char					*get_groupname(uid_t uid);
char					*get_username(uid_t uid);
void					file_ls(char *path, size_t *max);
char					*ft_joinpath(char *pat, char *nam);
t_fold					*addtolist(t_fold *start, char *path);
void					ft_swap(t_save *ok, t_save *new, t_save **tmp, \
						t_save *before);
t_save					*trithat(t_save *go);
int						file_exist(char *filename);
t_fold					*free_listt(t_fold *lst);
t_save					*addtoshow(char *name, char *path, t_save *go, \
						unsigned char type);
void					showthat(t_save *go, int *arg, char *path, size_t *max);
void					free_list(t_save *go);
void					majorminor(struct stat *sb, char filetype, size_t *max);\
void					ft_print_nb(int spaces, long long int nb);

#endif
