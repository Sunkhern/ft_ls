/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:24:52 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 17:54:25 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <sys/types.h>
# include <pwd.h>
# include "libft/libft.h"
# include <time.h>
# include <errno.h>
# include <stdio.h>

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
void	print_time(char *time);
void	lswritemode(mode_t mode);
int		argcheck(char *core, int ct);
int		treat_core(char **core, int argnb);
void	print_l(struct stat mystat, int *sizes);
void	print_argnor(char **tab, int i, int arg, char *dir);
void	print_argr(char **tab, int i, int arg, char *dir);
void	printdata(char **tab, int len, int arg, char *dir);
void	swap(char **s1, char **s2);
void	getdata(char *tdir, int arg);
int		dirnb(char **tab);
char	**ft_sort(char **tab);
int		dirvalue(char *tdir);
char	**dirsort(char **src, int arg);
void	argbigr(char **tab, char *tdir, int arg);
void	print_ismulti(char *tab, int arg);
void	print_ismultiln(int arg);
int		ismulti(char **tab);
char	**ft_sorttime(int ct, char **tab, char *dir);
char	**ft_sort(char **tab);
void	print_ismulti(char *tab, int arg);
int		minisizer(char **tab);
int		iswrongarg(int arg, char **tab);
int		littleln(int arg);
char	**ft_sorttimebigr(char **tab);
void	blocks(char **tab, char *dir, int arg);
int		dircheck(char *src);

#endif
