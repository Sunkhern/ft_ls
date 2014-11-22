/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 14:43:23 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 17:43:59 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		dirnb(char **tab)
{
	int				ct;
	int				i;
	DIR				*lsdir;
	struct dirent	*lsfile;

	ct = 0;
	i = 1;
	while (tab[i])
	{
		if ((lsdir = opendir(tab[i])))
			ct++;
		i++;
	}
	return (ct);
}

void	swap(char **s1, char **s2)
{
	char			*tmp;

	tmp = (char*)malloc(sizeof(char) * ft_strlen(*s2));
	tmp = *s2;
	*s2 = *s1;
	*s1 = tmp;
}

int		dirvalue(char *tdir)
{
	int				ct;
	DIR				*lsdir;
	struct dirent	*lsfile;

	lsdir = opendir(tdir);
	while ((lsfile = readdir(lsdir)) != NULL)
		ct++;
	closedir(lsdir);
	return (ct);
}

int		dircheck(char *src)
{
	int				ct;
	DIR				*lsdir;
	struct dirent	*lsfile;

	ct = 1;
	if (!(lsdir = opendir(src)))
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(src, 2);
		ft_putstr_fd(" : ", 2);
		perror("");
		ct = 0;
	}
	return (ct);
}
