/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:02:48 by blucas            #+#    #+#             */
/*   Updated: 2017/01/17 13:28:46 by jlasne           ###   ########.fr       */
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
# include <locale.h>
# include <langinfo.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

int				*arg_parser(char *str, int *arg);
int				*ft_setint(int size);
void			ft_ls(char *path, int *arg);
#endif

