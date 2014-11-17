/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:24:45 by wromano           #+#    #+#             */
/*   Updated: 2014/11/17 20:55:45 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

int		getdata(char *tdir, int arg)
{
	int				i;
	int				len;
	DIR				*lsdir;
	struct dirent	*lsfile;
	char			**tab;

	i = 0;
	lsdir = opendir(tdir);
	tab = (char **)ft_memalloc(sizeof(char *) * dirvalue(tdir) + 1);
	while ((lsfile = readdir(lsdir)) != NULL)
	{
		if (arg % 7 == 0)
		{
			tab[i] = ft_strdup(lsfile->d_name);
			i++;
		}
		else if (ft_strncmp(lsfile->d_name, ".", 1) != 0)
		{
			tab[i] = ft_strdup(lsfile->d_name);
			i++;
		}
	}
	tab[i] = NULL;
	printdata(tab, i, arg, tdir);
	closedir(lsdir);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		arg;

	j = 0;
	i = 1;
	arg = treat_core(argv, argc);
	if (arg == -1)
	{
		ft_putstr("ls illegal option -- ");
		return (0);
	}
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			getdata(argv[i], arg);
			j = 1;
		}
		i++;
	}
	if (j == 0)
		getdata(".", arg);
	return (0);
}
