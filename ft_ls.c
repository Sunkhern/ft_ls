/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:24:45 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 17:57:23 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	getargr(char **tab, char *tdir, int arg)
{
	if (arg % 5 == 0)
	{
		if (arg % 23 != 0)
			arg = arg * 23;
		argbigr(tab, tdir, arg);
	}
}

void	getdata(char *tdir, int arg)
{
	int				i;
	DIR				*lsdir;
	struct dirent	*lsfile;
	char			**tab;

	i = 0;
	if (!(lsdir = opendir(tdir)))
		return ;
	tab = (char **)ft_memalloc(sizeof(char *) * dirvalue(tdir) + 1);
	while ((lsfile = readdir(lsdir)) != NULL)
	{
		tab[i] = ft_strdup(lsfile->d_name);
		i++;
	}
	tab[i] = NULL;
	tab = ft_sort(tab);
	printdata(tab, i, arg, tdir);
	arg = littleln(arg);
	getargr(tab, tdir, arg);
	free(tab);
	closedir(lsdir);
}

int		rev_treatment(char **argv, char **tab, int arg)
{
	int i;
	int j;

	i = dirnb(argv) - 1;
	j = 0;
	while (i >= 0)
	{
		if (tab[i][0] != '-')
		{
			getdata(tab[i], arg);
			j = 1;
		}
		i--;
	}
	return (j);
}

int		first_treatment(char **argv, char **tab, int arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (arg % 11 == 0)
		j = rev_treatment(argv, tab, arg);
	else
	{
		while (i < dirnb(argv))
		{
			if (tab[i][0] != '-')
			{
				getdata(tab[i], arg);
				j = 1;
			}
			i++;
		}
	}
	return (j);
}

int		main(int argc, char **argv)
{
	int		ct;
	int		j;
	int		arg;
	char	**tab;

	ct = 0;
	j = 0;
	arg = treat_core(argv, argc);
	if (argc > 1)
	{
		if (argv[1][0] != '-')
			arg = 1;
	}
	if (iswrongarg(arg, argv) == 0)
		return (0);
	if (ismulti(argv) == 1)
		arg = arg * 17;
	if (argc > 1 && dirnb(argv) > 0)
		tab = dirsort(argv, arg);
	if (arg % 17 == 0)
		tab = ft_sorttime(ct, tab, "");
	j = first_treatment(argv, tab, arg);
	if (j == 0)
		getdata(".", arg);
	return (0);
}
