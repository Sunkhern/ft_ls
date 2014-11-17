/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:24:52 by wromano           #+#    #+#             */
/*   Updated: 2014/11/17 20:53:16 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include <sys/stat.h>
#include <grp.h>
#include <sys/types.h>
#include <pwd.h>
#include "libft/libft.h"
#include <time.h>

int		intsize(int i);
int		*maxsize(char **tab, char *dir);
int		nlinksize(char **tab, char *dir);
int		uidsize(char **tab, char *dir);
int		gidsize(char **tab, char *dir);
int		sizesize(char **tab, char *dir);
int		sizemin(char **tab, char *dir);
int		sizemaj(char **tab, char *dir);
void	print_sizei(int size, int data);
void	print_sizec2(int size, char *data);
void	print_sizec(int size, char *data);
void	print_majmin(int *size, int major, int minor);
void	print_time(char *time, char *dir);
void	lswritemode(mode_t mode);
int		argcheck(char *core, int ct);
int		treat_core(char **core, int argnb);
void	print_l(struct stat mystat, int *sizes, char *dir);
void	print_argnor(char **tab, int i, int arg, char *dir);
void	print_argr(char **tab, int i, int arg, char *dir);
void	printdata(char **tab, int len, int arg, char *dir);

#endif
