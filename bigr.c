/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 14:48:35 by wromano           #+#    #+#             */
/*   Updated: 2014/11/21 19:12:38 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		taballoc(char **tab, char *tdir)
{
	int			ct;
	int			i;
	struct stat	mystat;
	char		*buf;
	char		**tab2;

	ct = 0;
	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], ".") != 0 && ft_strcmp(tab[i], "..") != 0)
		{
			buf = ft_strjoin(tdir, tab[i]);
			lstat(buf, &mystat);
			if (S_ISDIR(mystat.st_mode))
				ct++;
			free(buf);
		}
		i++;
	}
	return (ct);
}

void	argbigr2(char **tab, char *tdir, int arg)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		getdata(tab[i], arg);
		i++;
	}
}

char	**argbigrr(int i, char **tab, char *tdir, int arg)
{
	int			j;
	char		*buf;
	char		**tab2;
	struct stat	mystat;

	tdir = ft_strjoin(tdir, "/");
	j = 0;
	buf = ft_strjoin(tdir, tab[i]);
	tab2 = (char **)ft_memalloc(sizeof(char *) * taballoc(tab, tdir) + 1);
	i = minisizer(tab);
	while (i >= 0)
	{
		buf = ft_strjoin(tdir, tab[i]);
		lstat(buf, &mystat);
		if (S_ISDIR(mystat.st_mode) && ft_strcmp(tab[i], ".") != 0
			&& ft_strcmp(tab[i], "..") != 0)
		{
			tab2[j] = ft_strdup(buf);
			j++;
		}
		i--;
		free(buf);
	}
	tab2[j] = NULL;
	return (tab2);
}

char	**argbigrnor(int i, char **tab, char *tdir, int arg)
{
	int			j;
	char		*buf;
	char		**tab2;
	struct stat	mystat;

	tdir = ft_strjoin(tdir, "/");
	j = 0;
	buf = ft_strjoin(tdir, tab[i]);
	tab2 = (char **)ft_memalloc(sizeof(char *) * taballoc(tab, tdir) + 1);
	while (tab[i])
	{
		buf = ft_strjoin(tdir, tab[i]);
		lstat(buf, &mystat);
		if (S_ISDIR(mystat.st_mode) && ft_strcmp(tab[i], ".") != 0
			&& ft_strcmp(tab[i], "..") != 0)
		{
			tab2[j] = ft_strdup(buf);
			j++;
		}
		i++;
		free(buf);
	}
	tab2[j] = NULL;
	return (tab2);
}

void	argbigr(char **tab, char *tdir, int arg)
{
	int		i;
	char	**tab2;

	tab = ft_sort(tab);
	i = 0;
	if (arg % 13 == 0)
		tab = ft_sorttime(i, tab, ft_strjoin(tdir, "/"));
	if (arg % 11 == 0)
		tab2 = argbigrr(i, tab, tdir, arg);
	else
		tab2 = argbigrnor(i, tab, tdir, arg);
	argbigr2(tab2, tdir, arg);
}
